// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "DiscardedDeck.h"
#include "Components/StaticMeshComponent.h"

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
	//int Index = 0;
	//
	//checkf(PossibleCardsList.Num() > 0, TEXT("No cards were placed in the possible cards list"));
	//if (PossibleCardsList.Num() > 0)
	//{
	//	while (Cards.Num() < MaxCapacity)
	//	{
	//		int CardIndex = FMath::RandRange(0, PossibleCardsList.Num() - 1);
	//		FActorSpawnParameters SpawnInfo;
	//		AActor* MySpawnedActor = GetWorld()->SpawnActor<ACard>(PossibleCardsList[CardIndex], SpawnInfo);
	//		if (MySpawnedActor)
	//		{
	//			if (!AddCard(Cast<ACard>(MySpawnedActor)))
	//			{
	//				UE_LOG(LogTemp, Error, TEXT("Card %s couldn't be added to the deck"), PossibleCardsList[CardIndex].Get());
	//			}
	//		}
	//
	//		Index++;
	//	}
	//}
}

// Called when the game starts or when spawned
void ADeck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
