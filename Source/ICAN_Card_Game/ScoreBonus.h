// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "ScoreBonus.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ICAN_CARD_GAME_API UScoreBonus : public UObject
{
	GENERATED_BODY()

public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//TSubclassOf<class UScoreBonusOperand> Operand;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BonusValue;

	UPROPERTY(EditAnywhere)
	bool bIsBonusEnabled;

	UFUNCTION(BlueprintImplementableEvent)
	float SetBonusValue(float InitialBonusValue, const TArray<ACard*>& Cards);
};
