#include "DiscardedDeck.h"
// Fill out your copyright notice in the Description page of Project Settings.

// Sets default values
ADiscardedDeck::ADiscardedDeck()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	StaticMeshComponent->SetupAttachment(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADiscardedDeck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADiscardedDeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ADiscardedDeck::AddCard(ACard* Card)
{
	if (Card && Cards.Num() < MaxCapacity)
	{
		Cards.Add(Card);
		Card->Status = ECardStatus::IN_DISCARD;
		return true;
	}

	return false;
}

bool ADiscardedDeck::RemoveCard(ACard* Card)
{
	if (Card && Cards.Num() > 0)
	{
		Cards.Remove(Card);
		return true;
	}

	return false;
}

void ADiscardedDeck::UpdateCollectionVisuals()
{
	FVector ActorLocation = GetActorLocation();
	FVector Og;
	FVector BoxExtent;

	GetActorBounds(true, Og, BoxExtent);

	for (int i = 0; i < Cards.Num(); i++)
	{
		FVector Location(ActorLocation.X, ActorLocation.Y, (ActorLocation.Z - BoxExtent.Z) + (i * 1.0f));
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FVector Scale = FVector(0.2f, 0.2f, 0.2f);

		Cards[i]->SetActorLocation(Location);
		Cards[i]->SetActorRotation(Rotation);
		Cards[i]->SetActorScale3D(Scale);
	}
}

