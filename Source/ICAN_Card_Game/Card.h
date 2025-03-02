// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardData.h"
#include "Card.generated.h"

UENUM(BlueprintType)
enum class ECardStatus : uint8 {
	IN_DECK = 0 UMETA(DisplayName = "DECK"),
	IN_HAND = 1  UMETA(DisplayName = "HAND"),
	IN_DISCARD = 2     UMETA(DisplayName = "DISCARD"),
	IN_SLOT = 3     UMETA(DisplayName = "IN_SLOT")
};

UCLASS()
class ICAN_CARD_GAME_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	ECardStatus Status = ECardStatus::IN_DECK;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	UCardData* CardDataComp = nullptr;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComp = nullptr;

	bool bIsCardSelected = false;
	bool bIsCardSet = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PlayCard();

	UFUNCTION(BlueprintCallable)
	inline UCardData* GetCardDataComp() {return CardDataComp;};

};
