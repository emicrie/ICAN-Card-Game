// Fill out your copyright notice in the Description page of Project Settings.


#include "ACardHolder.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACardHolder::ACardHolder()
{
	CardDataComp = CreateDefaultSubobject<UCardData>(TEXT("Card Data"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardHolder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACardHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

