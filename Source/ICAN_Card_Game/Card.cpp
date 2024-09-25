// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "CardHand.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACard::ACard()
{
	CardDataComp = CreateDefaultSubobject<UCardData>(TEXT("Card Data"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));

	MeshComp->SetupAttachment(RootComponent);
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//TODO: This function shouldn't have to know anything about decks or hands, all these infos should be in some sort of manager class maybe
void ACard::PlayCard(ADiscardedDeckActor* DiscardedDeck, ACardHand* Hand)
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
			Hand->DisplayHand();
		}
	}

	
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

