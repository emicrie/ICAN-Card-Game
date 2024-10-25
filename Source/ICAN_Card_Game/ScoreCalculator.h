// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/TextRenderActor.h"
#include "ScoreCalculator.generated.h"

USTRUCT()
struct FRuleStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UScoreRule> Rule;
	UPROPERTY(EditAnywhere)
	bool bIsDefiniteValue = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition="bIsDefiniteValue==true", EditConditionHides))
	float DefiniteValue = 0;
	UPROPERTY(EditAnywhere, meta = (EditCondition="bIsDefiniteValue==false", EditConditionHides))
	TSubclassOf<class UScoreBonus> Bonus;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UScoreBonusOperand> Operand;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICAN_CARD_GAME_API UScoreCalculator : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScoreCalculator();

	UPROPERTY()
	int FinalResult = 0;

	UPROPERTY(EditAnywhere)
	TArray<FRuleStruct> MyRules;

	UPROPERTY(EditAnywhere)
	ATextRenderActor* TextActor = nullptr;
	
	//UPROPERTY(EditAnywhere)
	//TArray<TSubclassOf<class UScoreRule>> Rules;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	static UScoreCalculator* Instance;

	void AddToTextActor(FString TextToAdd);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category = "ScoreCalculator")
	static UScoreCalculator* GetInstance();

	int CalculateScore(TArray<class ACard*> PlayedCards);

		
};
