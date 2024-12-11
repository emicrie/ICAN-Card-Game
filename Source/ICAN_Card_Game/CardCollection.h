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
	
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "New system")
	TArray<int> Contents;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "New system")
	TArray<ACard*> Cards;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "New system")
	FTransform OriginTransform;

	int ContentNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "New system", meta = (EditCondition = "!bInfiniteCapacity"))
	int MaxCapacity = 99;

	UPROPERTY(EditAnywhere, Category = "New system")
	bool bInfiniteCapacity = false;

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();

	UFUNCTION(BlueprintCallable)
	virtual void InitCollection();

	UFUNCTION(BlueprintImplementableEvent)
	void AddCardBP(int Value, int CollectionLocationToPutAt);

	UFUNCTION(BlueprintImplementableEvent)
	void RemoveCardBP(int CollectionLocation);

	UFUNCTION(BlueprintCallable)
	virtual bool AddCard(int CardID, int PositionToMoveAt = 0);

	UFUNCTION(BlueprintCallable)
	virtual bool SetCard(int CardPosInList, const int Index);

	UFUNCTION(BlueprintCallable)
	virtual bool RemoveCard(int CardPosInList);

	UFUNCTION()
	virtual void UpdateCollectionVisuals();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCollectionVisualsToMatchCollectionData(const ACardCollection* Collection);

	UFUNCTION(BlueprintImplementableEvent)
	void EmptyCardsList();

	UFUNCTION(BlueprintCallable)
	virtual bool Shuffle();

	UFUNCTION(BlueprintCallable)
	virtual bool IsCollectionFull();

	UFUNCTION()
	void BindDynamicsToDelegate();

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
