// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayedCardMat.h"
#include "CardSlotComponent.h"
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

bool APlayedCardMat::AddCard(class ACard* Card)
{
	if (Card && Cards.Num() < MaxCapacity)
	{
		Cards.Insert(Card, 0);
		Card->Status = ECardStatus::IN_SLOT;
		Cards[0]->bIsCardSet = true;
		return true;
	}
	
	return false;
}

bool APlayedCardMat::RemoveCard(class ACard* Card)
{
	return Super::RemoveCard(Card);
}

bool APlayedCardMat::SetCard(ACard* Card, const int Index)
{
	//Sanity check, thanks to CardCollection's Initialize, the cards should never be empty
	if(Cards.IsEmpty())
	{
		Cards.AddDefaulted(MaxCapacity);
	}
	
	if(Index < MaxCapacity)
	{
		if(Card != nullptr)
		{
			Cards[Index] = Card;
			Cards[Index]->bIsCardSet = true;
		}

		if(IsCollectionFull())
		{
			UE_LOG(LogTemp, Warning, TEXT("The played mat has been filled!"));
		}
		return true;
	}
	
	return false;
}

void APlayedCardMat::UpdateCollectionVisuals()
{
	GetSlotComps();

	checkf(SlotComps.Num() <= Cards.Num(), TEXT("The number of cards is over the MaxCapacity"));
	for(int i = 0; i < MaxCapacity; i++)
	{
		if (Cards.Num() > 0 && Cards[i] != nullptr)
		{
			if(Cards[i]->bIsCardSet)
			{
				Cards[i]->SetActorLocation(SlotComps[i]->GetComponentLocation());
			}
		}
	}
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

bool APlayedCardMat::IsMatFilled()
{
	bool bResult = true;
	for(int i = 0; i < MaxCapacity; i++)
	{
		if(Cards[i] == nullptr || !Cards[i]->bIsCardSet)
		{
			bResult = false;
			break;
		}
	}

	return bResult;
}

void APlayedCardMat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
