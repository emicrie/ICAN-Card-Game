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

UCLASS(BlueprintType, Blueprintable)
class ICAN_CARD_GAME_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Card Visuals")
	int CardID = -1;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Card Visuals", meta = (AllowPrivateAccess = "true"))
	UCardData* CardDataComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Visuals", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComp = nullptr;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Card State", meta = (AllowPrivateAccess = "true"))
	ECardStatus Status = ECardStatus::IN_DECK;

	UPROPERTY(Replicated, EditAnywhere, Category = "Card State", BlueprintReadWrite)
	bool bIsCardSelected = false;


protected:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	UFUNCTION(BlueprintCallable)
	inline UCardData* GetCardDataComp() {return CardDataComp;};

};
