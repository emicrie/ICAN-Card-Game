// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScoreBonusOperand.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ICAN_CARD_GAME_API UScoreBonusOperand : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	int Apply(int CurScore, float Value);

	UPROPERTY(EditAnywhere)
	FText OperandName;
	
};
