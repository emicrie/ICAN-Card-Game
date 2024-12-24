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
	
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category="Components")
	int ID = 0;

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
