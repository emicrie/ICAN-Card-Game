// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADeck::ADeck()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	StaticMeshComponent->SetupAttachment(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
