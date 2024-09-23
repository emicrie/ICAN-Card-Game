#include "DiscardedDeckActor.h"
#include "ACardHolder.h"
// Fill out your copyright notice in the Description page of Project Settings.

// Sets default values
ADiscardedDeckActor::ADiscardedDeckActor()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	StaticMeshComponent->SetupAttachment(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADiscardedDeckActor::PutInDiscard(ACardHolder* CardToDiscard)
{
	FVector ActorLocation = GetActorLocation();
	FVector Og;
	FVector BoxExtent;

	GetActorBounds(true, Og, BoxExtent);

	FVector SpawnLocation(ActorLocation.X, ActorLocation.Y, (ActorLocation.Z - BoxExtent.Z) + (DiscardedCards.Num() * 1.0f));
	FRotator SpawnRotation(0.0f, 0.0f, 0.0f);

	Cast<AActor>(CardToDiscard)->SetActorLocation(SpawnLocation);
	Cast<AActor>(CardToDiscard)->SetActorRotation(SpawnRotation);
	DiscardedCards.Insert(CardToDiscard, 0);
}

// Called when the game starts or when spawned
void ADiscardedDeckActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADiscardedDeckActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

