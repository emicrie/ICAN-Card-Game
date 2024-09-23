// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "DeckActor.generated.h"

UCLASS()
class ICAN_CARD_GAME_API ADeckActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeckActor();

	UPROPERTY(EditAnywhere)
	class ACardHand* CardHand = nullptr;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class ACardHolder>> CardList;

	UFUNCTION()
	void FillDeck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
