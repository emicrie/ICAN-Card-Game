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
