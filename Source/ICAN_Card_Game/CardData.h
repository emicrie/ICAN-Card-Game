// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CardData.generated.h"


UENUM(BlueprintType)
enum CardStrength : uint8
{
	IDOU = 0,
	ESSA = 1,
	ULTIS = 2,
};

UENUM(BlueprintType)
enum PlacementInSentence : uint8
{
	AMPLIFICATION = 0,
	BODY = 1,
	FLAVOR = 2,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICAN_CARD_GAME_API UCardData : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCardData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<CardStrength> Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<PlacementInSentence> Placement;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
