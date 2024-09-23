// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckActor.h"
#include "ACardHolder.h"
#include "CardHand.h"
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
	for (int i = 0; i < CardList.Num(); ++i)
	{
		FVector ActorLocation = GetActorLocation();
		FVector SpawnLocation(ActorLocation.X, ActorLocation.Y, ActorLocation.Z * i);
		FRotator SpawnRotation(0.0f, 0.0f, 0.0f);
		FVector SpawnScale = FVector(0.5f, 0.5f, 0.5f);
		FTransform SpawnTransform = FTransform(SpawnRotation, SpawnLocation, SpawnScale);
		FActorSpawnParameters SpawnInfo;
		AActor* MySpawnedActor = GetWorld()->SpawnActor<ACardHolder>(CardList[i], SpawnTransform, SpawnInfo);

		if (CardHand)
		{
			CardHand->CardList.Insert(Cast<ACardHolder>(MySpawnedActor), 0);
			CardHand->DisplayHand();
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

