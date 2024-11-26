// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.h"
#include "CardCollectionDelegates.h"
#include "ReplicatedCardCollection.h"
#include "CardCollection.generated.h"

UCLASS(Abstract, Blueprintable)
class ICAN_CARD_GAME_API ACardCollection : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACardCollection();
	
	UPROPERTY(Replicated, EditAnywhere)
	TArray<ACard*> Cards;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bInfiniteCapacity"))
	int MaxCapacity = 99;

	UPROPERTY(EditAnywhere)
	bool bInfiniteCapacity = false;

	UFUNCTION(BlueprintCallable)
	virtual void InitCollection();

	UFUNCTION(BlueprintCallable)
	virtual bool AddCard(ACard* Card);

	UFUNCTION(BlueprintCallable)
	virtual bool SetCard(ACard* Card, const int Index);

	UFUNCTION(BlueprintCallable)
	virtual bool RemoveCard(ACard* Card);

	UFUNCTION()
	virtual void UpdateCollectionVisuals();

	UFUNCTION()
	virtual void MatchVisualsToData(const UReplicatedCardCollection* Collection);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCollectionVisualsToMatchCollectionData(const UReplicatedCardCollection* Collection);

	UFUNCTION(BlueprintCallable)
	virtual bool Shuffle();

	UFUNCTION(BlueprintCallable)
	virtual bool IsCollectionFull();

	UFUNCTION()
	void BindDynamicsToDelegate();

	UPROPERTY(EditAnywhere, Category = "Card Collection")
	ECardCollectionType CollectionType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	struct FTimerHandle InitTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
