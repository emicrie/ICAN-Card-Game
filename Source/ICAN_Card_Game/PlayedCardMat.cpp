// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayedCardMat.h"
#include "CardSlotComponent.h"
#include "ScoreCalculator.h"

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

	TArray<UCardSlotComponent*> SlotsInActor;
	GetComponents(SlotsInActor);
	MaxCapacity = SlotsInActor.Num();

	int Index = 0;
	for (UCardSlotComponent* CardSlot : SlotsInActor)
	{
		CardSlot->ID = Index;
		Index++;
	}

	Contents.Reserve(MaxCapacity);
	Contents.Init(-1, MaxCapacity);
	Cards.Reserve(MaxCapacity);
	Cards.AddDefaulted(MaxCapacity);
}

void APlayedCardMat::ValidateFilledMat()
{
	UScoreCalculator::GetInstance()->FinalResult = UScoreCalculator::GetInstance()->CalculateScore(Cards);
}
