// Fill out your copyright notice in the Description page of Project Settings.
#include "ScoreCalculator.h"
#include "Card.h"
#include "ScoreBonus.h"
#include "ScoreBonusOperand.h"
#include "ScoreRule.h"
#include "Components/TextRenderComponent.h"
#include "Net/UnrealNetwork.h"

UScoreCalculator* UScoreCalculator::Instance = nullptr;

// Sets default values for this component's properties
UScoreCalculator::UScoreCalculator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UScoreCalculator* UScoreCalculator::GetInstance()
{
	return Instance;
}

int UScoreCalculator::CalculateScore(TArray<ACard*> PlayedCards)
{
	float Score = 0.0f;
	TextActor->GetTextRender()->SetText(FText::FromString(""));
	UE_LOG(LogTemp, Warning, TEXT("================SCORE CALCULATION================"));
	
	for(int i = 0; i < PlayedCards.Num(); i++)
	{
		if (PlayedCards[i] && PlayedCards[i]->CardID >= 0)
		{
			FString CardDebug = FString(PlayedCards[i]->GetCardDataComp()->Name + ", ID: " + FString::SanitizeFloat(PlayedCards[i]->CardID) + ",  Strength: " + FString::SanitizeFloat(PlayedCards[i]->GetCardDataComp()->Strength+1) + ", Placement: " + FString::SanitizeFloat(PlayedCards[i]->GetCardDataComp()->Placement));
			UE_LOG(LogTemp, Warning, TEXT("%s"), *CardDebug);
			FString CardBaseInfo = FString(PlayedCards[i]->GetCardDataComp()->Name);
			CardBaseInfo += FString(": " + FString::FromInt((int32)PlayedCards[i]->GetCardDataComp()->Strength + 1) + " + ");
			AddToTextActor(CardBaseInfo);
			Score += PlayedCards[i]->GetCardDataComp()->Strength + 1;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Current Score: %f"), Score);
	AddToTextActor(FString("Score: ") + FString::FromInt((int32)Score));
	
	for(int i = 0; i < MyRules.Num(); i++)
	{
		UScoreRule* CurRule = MyRules[i].Rule.GetDefaultObject();
		if(CurRule && CurRule->bValidateRule(PlayedCards))
		{
			FString RuleBonus = FString(CurRule->RuleName.ToString() + ": ");
			
			UE_LOG(LogTemp, Warning, TEXT("Rule %s was validated"), *CurRule->RuleName.ToString());

			if(MyRules[i].bIsDefiniteValue)
			{
				//FString DefValueString = FString("Bonus is DefiniteValue: " + FString::SanitizeFloat(MyRules[i].DefiniteValue));
				//AddToTextActor(DefValueString);
				
				UE_LOG(LogTemp, Warning, TEXT("Applying definite %f bonus"), MyRules[i].DefiniteValue);
				
				//FString AddedBonus = FString("Bonus value: " + FString::SanitizeFloat(MyRules[i].DefiniteValue));
				//AddToTextActor(AddedBonus);

				UScoreBonusOperand* CurOperand = MyRules[i].Operand.GetDefaultObject();
				UE_LOG(LogTemp, Warning, TEXT("Applying %s operand (%f)"), *CurOperand->GetName(), MyRules[i].DefiniteValue);
				
				RuleBonus += FString(CurOperand->OperandName.ToString());
				RuleBonus += FString::FromInt((int32)MyRules[i].DefiniteValue);
				AddToTextActor(RuleBonus);
				Score = CurOperand->Apply(Score, MyRules[i].DefiniteValue);
			}
			else
			{
				if (MyRules[i].Bonus)
				{
					UScoreBonus* CurBonus = MyRules[i].Bonus.GetDefaultObject();
					if (CurBonus)
					{
						FString CurBonusName = FString("Bonus: " + CurBonus->GetName());
						//AddToTextActor(CurBonusName);

						float FinalBonusValue = CurBonus->SetBonusValue(CurBonus->BonusValue, PlayedCards);

						FString AddedBonus = FString("Bonus value: " + FString::SanitizeFloat(FinalBonusValue));
						//AddToTextActor(AddedBonus);

						UScoreBonusOperand* CurOperand = MyRules[i].Operand.GetDefaultObject();
						UE_LOG(LogTemp, Warning, TEXT("Applying %s operand (%f)"), *CurOperand->GetName(), FinalBonusValue);

						RuleBonus += FString(CurOperand->OperandName.ToString());
						RuleBonus += FString::SanitizeFloat(FinalBonusValue);
						AddToTextActor(RuleBonus);

						Score = CurOperand->Apply(Score, FinalBonusValue);
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("No bonus for rule %s was found!"), *CurRule->GetName());
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Rule %s was invalidated!!!"), *CurRule->GetName());
		}
	}

	FString Final = TEXT("Final score: ");
	Final += FString::FromInt((int32)Score);
	AddToTextActor(Final);

	DebugScoreText = TextActor->GetTextRender()->Text.ToString();
	
	UE_LOG(LogTemp, Warning, TEXT("Final Score: %f"), Score);
	return FMath::CeilToInt(Score);
}


// Called when the game starts
void UScoreCalculator::BeginPlay()
{
	Super::BeginPlay();
	
	if(!Instance)
	{
		Instance = this;
	}
	
}

void UScoreCalculator::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if(Instance)
	{
		Instance->RemoveFromRoot();
		Instance = nullptr;
	}
}


void UScoreCalculator::AddToTextActor(FString TextToAdd, bool LineReturn)
{
	if(TextActor)
	{
		FString CurText = TextActor->GetTextRender()->Text.ToString();
		if (LineReturn)
		{
			TextActor->GetTextRender()->SetText(FText::FromString(CurText + TEXT("\n") + TextToAdd));
		}
		else
		{
			TextActor->GetTextRender()->SetText(FText::FromString(CurText + TextToAdd));
		}
	}
}

// Called every frame
void UScoreCalculator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UScoreCalculator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UScoreCalculator, DebugScoreText);
}

