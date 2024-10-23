// Fill out your copyright notice in the Description page of Project Settings.


#include "CardCollection.h"

// Sets default values
ACardCollection::ACardCollection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardCollection::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACardCollection::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Cards.Reset();
}

// Called every frame
void ACardCollection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACardCollection::InitCollection()
{
	Cards.AddDefaulted(MaxCapacity);
}

bool ACardCollection::AddCard(ACard* Card)
{
	Card->bIsCardSet = true;
	return true;
}

bool ACardCollection::SetCard(ACard* Card, const int Index)
{
	if(Index < MaxCapacity)
	{
		if(Card != nullptr)
		{
			Cards[Index] = Card;
			Cards[Index]->bIsCardSet = true;
		}
		return true;
	}
	
	return false;
}

bool ACardCollection::RemoveCard(ACard* Card)
{
	return true;
}

bool ACardCollection::Shuffle()
{
	return true;
}

bool ACardCollection::IsCollectionFull()
{
	return Cards.Num() == MaxCapacity;
}

void ACardCollection::UpdateCollectionVisuals()
{

}
