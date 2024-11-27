// Fill out your copyright notice in the Description page of Project Settings.


#include "Hand.h"

// Sets default values
AHand::AHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHand::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AHand::AddCard(ACard* Card)
{
	if (Card && Cards.Num() < MaxCapacity)
	{
		Cards.Add(Card);
		Card->Status = ECardStatus::IN_HAND;
		return true;
	}

	return false;
}

bool AHand::RemoveCard(ACard* Card)
{
	if (Card && Cards.Num() > 0)
	{
		Cards.Remove(Card);
		return true;
	}

	return false;
}

void AHand::UpdateCollectionVisuals()
{
	FVector ActorLocation = GetActorLocation();

	FVector Og;
	FVector BoxExtent;

	for (int i = 0; i < Cards.Num(); ++i)
	{
		Cards[i]->GetActorBounds(true, Og, BoxExtent);

		FVector Location(ActorLocation.X, ActorLocation.Y + ((i * (BoxExtent.Y * 2.5f))), ActorLocation.Z + (i * 0.001f));
		FRotator Rotation(-90.0f, 0.0f, 0.0f);

		Cast<AActor>(Cards[i])->SetActorLocation(Location);
		Cast<AActor>(Cards[i])->SetActorRotation(Rotation);
	}
}

// Called every frame
void AHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

