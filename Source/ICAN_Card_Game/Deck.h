// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "CardCollection.h"
#include "ReplicatedDeck.h"
#include "Hand.h"
#include "Deck.generated.h"

UCLASS()
class ICAN_CARD_GAME_API ADeck : public ACardCollection
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

	UPROPERTY(EditAnywhere)
	class AHand* Hand = nullptr;

	UPROPERTY(EditAnywhere)
	class ADiscardedDeck* DiscardedDeck = nullptr;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "New system")
	TObjectPtr<UDataTable> DeckDataTable;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class ACard>> PossibleCardsList;

	UFUNCTION(BlueprintCallable)
	void FillDeck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
