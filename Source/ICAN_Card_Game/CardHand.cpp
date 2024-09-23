// Fill out your copyright notice in the Description page of Project Settings.


#include "CardHand.h"
#include "ACardHolder.h"

// Sets default values
ACardHand::ACardHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardHand::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACardHand::DisplayHand()
{
	for (int i = 0; i < CardList.Num(); ++i)
	{
		FVector ActorLocation = GetActorLocation();
		FVector SpawnLocation(ActorLocation.X * i, ActorLocation.Y, ActorLocation.Z);
		FRotator SpawnRotation(0.0f, 0.0f, 0.0f);
		FVector SpawnScale = FVector(0.5f, 0.5f, 0.5f);
		FTransform SpawnTransform = FTransform(SpawnRotation, SpawnLocation, SpawnScale);
		FActorSpawnParameters SpawnInfo;
		
		//AActor* MySpawnedActor = GetWorld()->SpawnActor<ACardHolder>(CardList[i], SpawnTransform, SpawnInfo);
	}
}

// Called every frame
void ACardHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

