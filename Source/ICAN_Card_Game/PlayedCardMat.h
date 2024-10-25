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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void GetSlotComps();

	TArray<class UCardSlotComponent*> SlotComps;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//*--- ACardCollectionInterface
	virtual bool AddCard(class ACard* Card) override;
	virtual bool SetCard(ACard* Card, const int Index) override;
	virtual bool RemoveCard(class ACard* Card) override;
	virtual void UpdateCollectionVisuals() override;
	virtual void InitCollection() override;
	virtual bool IsCollectionFull() override;
	//*--- End of ACardCollectionInterface

	UFUNCTION(BlueprintCallable)
	void ValidateFilledMat();
	
};
