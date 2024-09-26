// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "DiscardedDeck.h"
#include "Components/StaticMeshComponent.h"

UE_DISABLE_OPTIMIZATION

// Sets default values
ADeck::ADeck()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	StaticMeshComponent->SetupAttachment(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADeck::FillDeck()
{
	int Index = 0;

	checkf(PossibleCardsList.Num() > 0, TEXT("No cards were placed in the possible cards list"));
	if (PossibleCardsList.Num() > 0)
	{
		while (Cards.Num() < Capacity)
		{
			int CardIndex = FMath::RandRange(0, PossibleCardsList.Num() - 1);
			FActorSpawnParameters SpawnInfo;
			AActor* MySpawnedActor = GetWorld()->SpawnActor<ACard>(PossibleCardsList[CardIndex], SpawnInfo);
			if (MySpawnedActor)
			{
				if (!AddCard(Cast<ACard>(MySpawnedActor)))
				{
					UE_LOG(LogTemp, Error, TEXT("Card %s couldn't be added to the deck"), PossibleCardsList[CardIndex].Get());
				}
			}

			Index++;
		}
	}
	UpdateCollectionVisuals();
}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();
	FillDeck();
	
}

bool ADeck::AddCard(ACard* Card)
{
	if (Card && Cards.Num() < Capacity)
	{
		Cards.Insert(Card, 0);
		Card->Status = ECardStatus::IN_DECK;
		UpdateCollectionVisuals();
		return true;
	}
	
	return false;
}

bool ADeck::RemoveCard(class ACard* Card)
{
	if (Card && Cards.Num() > 0)
	{
		Cards.Remove(Card);
		UpdateCollectionVisuals();
		return true;
	}

	return false;
}

void ADeck::UpdateCollectionVisuals()
{
	FVector ActorLocation = GetActorLocation();
	FVector Og;
	FVector BoxExtent;

	GetActorBounds(true, Og, BoxExtent);

	int Index = Cards.Num() - 1;
	for (int i = 0; i < Cards.Num(); i++)
	{
		FVector Location(ActorLocation.X, ActorLocation.Y, (ActorLocation.Z - BoxExtent.Z) + (i * 1.0f));
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FVector Scale = FVector(0.2f, 0.2f, 0.2f);

		Cards[Index]->SetActorLocation(Location);
		Cards[Index]->SetActorRotation(Rotation);
		Cards[Index]->SetActorScale3D(Scale);
		Index--;
	}
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

