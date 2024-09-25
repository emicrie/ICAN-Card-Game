// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hand.generated.h"

UCLASS()
class ICAN_CARD_GAME_API AHand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHand();

	UPROPERTY(EditAnywhere)
	TArray<class ACard*> CardsInHands;

	UPROPERTY(EditAnywhere)
	int MaxCapacity = 7;

	void DisplayHand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
