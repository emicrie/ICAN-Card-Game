// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.h"
#include "CardCollection.generated.h"

UCLASS(Abstract, Blueprintable)
class ICAN_CARD_GAME_API ACardCollection : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACardCollection();
	
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Collection Contents")
	TArray<int> Contents;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Collection Contents")
	TArray<ACard*> Cards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collection Parameters")
	FTransform OriginTransform;

	int ContentNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collection Parameters", meta = (EditCondition = "!bInfiniteCapacity"))
	int MaxCapacity = 99;

	UPROPERTY(EditAnywhere, Category = "Collection Parameters")
	bool bInfiniteCapacity = false;


protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
