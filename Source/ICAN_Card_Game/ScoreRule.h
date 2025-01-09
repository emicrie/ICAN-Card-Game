// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "ScoreRule.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ICAN_CARD_GAME_API UScoreRule : public UObject
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Rule|Validation")
	bool bValidateRule(const TArray<ACard*>& Cards);
	
	UPROPERTY(EditAnywhere)
	FText RuleName;
};
