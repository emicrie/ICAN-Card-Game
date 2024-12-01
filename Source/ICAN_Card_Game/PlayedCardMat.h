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

	UPROPERTY(EditAnywhere)
	bool bFilled = false;

protected:
	UFUNCTION(BlueprintCallable)
	void GetSlotComps();

	TArray<class UCardSlotComponent*> SlotComps;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	//*--- ACardCollectionInterface
	virtual void InitCollection() override;
	virtual bool IsCollectionFull() override;
	//*--- End of ACardCollectionInterface

	UFUNCTION(BlueprintCallable)
	void ValidateFilledMat();
	
};
