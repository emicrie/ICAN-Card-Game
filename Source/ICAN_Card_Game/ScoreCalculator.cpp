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
	
	for(int i = 0; i < PlayedCards.Num(); i++)
	{
		Score += PlayedCards[i]->GetCardDataComp()->Value;
	}
	UE_LOG(LogTemp, Warning, TEXT("Current Score: %f"), Score);
	
	for(int i = 0; i < MyRules.Num(); i++)
	{
		UScoreRule* CurRule = MyRules[i].Rule.GetDefaultObject();
		if(CurRule && CurRule->bValidateRule(PlayedCards))
		{
			FString RuleName = FString("Validated rule: " + CurRule->GetName());
			AddToTextActor(RuleName);
			
			UE_LOG(LogTemp, Warning, TEXT("Rule %s was validated"), *CurRule->GetName());

			if(MyRules[i].bIsDefiniteValue)
			{
				FString DefValueString = FString("Bonus is DefiniteValue: " + FString::SanitizeFloat(MyRules[i].DefiniteValue));
				AddToTextActor(DefValueString);
				
				UScoreBonusOperand* CurOperand = MyRules[i].Operand.GetDefaultObject();
				
				UE_LOG(LogTemp, Warning, TEXT("Applying definite %f bonus"), MyRules[i].DefiniteValue);
				
				FString AddedBonus = FString("Bonus value: " + FString::SanitizeFloat(MyRules[i].DefiniteValue));
				AddToTextActor(AddedBonus);
				
				Score = CurOperand->Apply(Score, MyRules[i].DefiniteValue);
			}
			else
			{
				if(MyRules[i].Bonus)
				{
					UScoreBonus* CurBonus = MyRules[i].Bonus.GetDefaultObject();
					if(CurBonus)
					{
						FString CurBonusName = FString("Bonus: " + CurBonus->GetName());
						AddToTextActor(CurBonusName);
						
						float FinalBonusValue = CurBonus->SetBonusValue(CurBonus->BonusValue, PlayedCards);

						FString AddedBonus = FString("Bonus value: " + FString::SanitizeFloat(FinalBonusValue));
						AddToTextActor(AddedBonus);
					
						UScoreBonusOperand* CurOperand = MyRules[i].Operand.GetDefaultObject();
						UE_LOG(LogTemp, Warning, TEXT("Applying %s bonus (%f)"), *CurBonus->GetName(), FinalBonusValue);
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

	FString Final = FString::SanitizeFloat(Score);
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


void UScoreCalculator::AddToTextActor(FString TextToAdd)
{
	if(TextActor)
	{
		FString CurText = TextActor->GetTextRender()->Text.ToString();
		TextActor->GetTextRender()->SetText(FText::FromString(CurText + TEXT("\n") + TextToAdd));
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

