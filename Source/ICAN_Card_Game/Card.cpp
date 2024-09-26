// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "Hand.h"
#include "DiscardedDeck.h"
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

void ACard::PlayCard()
{
	UE_LOG(LogTemp, Warning, TEXT("Playing %s !"), *GetName());
}
