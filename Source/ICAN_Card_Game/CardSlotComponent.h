// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CardSlotComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICAN_CARD_GAME_API UCardSlotComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UCardSlotComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	int ID = 0;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	class UCardCollectionsManager* CollectionManager = nullptr;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool Interact(class ACard*& Card) const;
};
