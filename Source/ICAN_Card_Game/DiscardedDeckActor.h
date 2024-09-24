// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiscardedDeckActor.generated.h"

UCLASS()
class ICAN_CARD_GAME_API ADiscardedDeckActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADiscardedDeckActor();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TArray<class ACard*> DiscardedCards;

	UFUNCTION()
	void PutInDiscard(ACard* CardToDiscard);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
