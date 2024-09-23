// Fill out your copyright notice in the Description page of Project Settings.


#include "ACardHolder.h"
#include "CardHand.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACardHolder::ACardHolder()
{
	CardDataComp = CreateDefaultSubobject<UCardData>(TEXT("Card Data"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACardHolder::PlayCard(ADiscardedDeckActor* DiscardedDeck, ACardHand* Hand)
{
	checkf(Hand, TEXT("There is no hand, this shouldn't happen! Make sure CardHand is set"));
	if (Hand)
	{
		checkf(DiscardedDeck, TEXT("There is no discarded deck to put cards into, this shouldn't happen! Make sure DiscardedDeck is set"));
		if (DiscardedDeck)
		{
			this->Status = ECardStatus::IN_DISCARD;
			DiscardedDeck->PutInDiscard(this);
			Hand->CardsInHands.Remove(this);
		}
	}

	
}

// Called when the game starts or when spawned
void ACardHolder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACardHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

