// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CardCollectionsManager.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ICAN_CARD_GAME_API UCardCollectionsManager : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCardCollectionsManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	static UCardCollectionsManager* Instance;

public:	

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable, Category = "CardCollections singleton")
	static UCardCollectionsManager* GetInstance();
};
