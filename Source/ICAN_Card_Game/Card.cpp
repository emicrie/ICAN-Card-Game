// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ACard::ACard()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	CardDataComp = CreateDefaultSubobject<UCardData>(TEXT("Card Data"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));

	MeshComp->SetupAttachment(RootComponent);
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACard::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACard, Status);
	DOREPLIFETIME(ACard, CardID);
	DOREPLIFETIME(ACard, CardDataComp);
	DOREPLIFETIME(ACard, bIsCardSelected);
}
