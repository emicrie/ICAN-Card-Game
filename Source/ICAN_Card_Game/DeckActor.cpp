// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckActor.h"
#include "Card.h"
#include "CardHand.h"
#include "DiscardedDeckActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADeckActor::ADeckActor()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	StaticMeshComponent->SetupAttachment(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADeckActor::FillDeck()
{
	int Index = 0;

	checkf(PossibleCardsList.Num() > 0, TEXT("No cards were placed in the possible cards list"));
	if (PossibleCardsList.Num() > 0)
	{
		while (SpawnedCardsList.Num() < Capacity)
		{
			int CardIndex = FMath::RandRange(0, PossibleCardsList.Num() - 1);

			FVector ActorLocation = GetActorLocation();
			FVector Og;
			FVector BoxExtent;

			GetActorBounds(true, Og, BoxExtent);

			FVector SpawnLocation(ActorLocation.X, ActorLocation.Y, (ActorLocation.Z - BoxExtent.Z) + (Index * 1.0f));
			FRotator SpawnRotation(0.0f, 0.0f, 0.0f);
			FVector SpawnScale = FVector(0.5f, 0.5f, 0.5f);
			FTransform SpawnTransform = FTransform(SpawnRotation, SpawnLocation, SpawnScale);
			FActorSpawnParameters SpawnInfo;
			AActor* MySpawnedActor = GetWorld()->SpawnActor<ACard>(PossibleCardsList[CardIndex], SpawnTransform, SpawnInfo);

			if (MySpawnedActor)
			{
				SpawnedCardsList.Insert(Cast<ACard>(MySpawnedActor), 0);
				Cast<ACard>(SpawnedCardsList[0])->Status = ECardStatus::IN_DECK;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("The card couldn't spawn, and as such, it wasn't added"));
			}

			Index++;
		}
	}

	CardHand->DisplayHand();
}

void ADeckActor::DrawCard(int NrOfCardsToDraw)
{
	PopulateHand(NrOfCardsToDraw);
}

void ADeckActor::PopulateHand(int NumberOfCardsToPutInHand)
{
	checkf(CardHand, TEXT("There is no hand to put cards into, this shouldn't happen! Make sure CardHand is set"));
	if (CardHand)
	{
		for (int i = 0; i < NumberOfCardsToPutInHand; ++i)
		{
			if (CardHand->CardsInHands.Num() < CardHand->MaxCapacity && SpawnedCardsList.Num() > 0)
			{
				CardHand->CardsInHands.Insert(Cast<ACard>(SpawnedCardsList[i]), 0);
				SpawnedCardsList.RemoveAt(i);
				Cast<ACard>(CardHand->CardsInHands[0])->Status = ECardStatus::IN_HAND;
				CardHand->DisplayHand();
			}
		}
	}
}

// Called when the game starts or when spawned
void ADeckActor::BeginPlay()
{
	Super::BeginPlay();
	FillDeck();
	
}

// Called every frame
void ADeckActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

