// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardCollection.h"
#include "PlayedCardMat.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API APlayedCardMat : public ACardCollection
{
	GENERATED_BODY()

public:

	APlayedCardMat();

	UPROPERTY(EditAnywhere)
	class UCardSlotComponent* CardSlotComp = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Played card mat status")
	bool bFilled = false;

public:	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ValidateFilledMat();
	
};
