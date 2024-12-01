// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayedCardMat.h"
#include "CardSlotComponent.h"
#include "ScoreCalculator.h"
#include "Components/StaticMeshComponent.h"

APlayedCardMat::APlayedCardMat()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	CardSlotComp = CreateDefaultSubobject<UCardSlotComponent>(TEXT("Slot Component"));
	CardSlotComp->SetupAttachment(RootComponent);
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APlayedCardMat::BeginPlay()
{
	Super::BeginPlay();

	InitCollection();
}

void APlayedCardMat::InitCollection()
{
	Super::InitCollection();
}

bool APlayedCardMat::IsCollectionFull()
{
	bool bIsFull = true;
	for(int i = 0; i < MaxCapacity; i++)
	{
		if(!Cards[i])
		{
			bIsFull = false;
		}
	}
	return bIsFull;
}

void APlayedCardMat::GetSlotComps()
{
	GetComponents(SlotComps);
	
	SlotComps.Sort([](const UCardSlotComponent& cs1, const UCardSlotComponent& cs2) {
	// access some random field just to test compile
	return  cs1.ID < cs2.ID; });
}

void APlayedCardMat::ValidateFilledMat()
{
	UScoreCalculator::GetInstance()->FinalResult = UScoreCalculator::GetInstance()->CalculateScore(Cards);
}

void APlayedCardMat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
