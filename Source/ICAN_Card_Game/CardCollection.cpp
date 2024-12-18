// Fill out your copyright notice in the Description page of Project Settings.


#include "CardCollection.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ACardCollection::ACardCollection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACardCollection::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Cards.Reset();
}

void ACardCollection::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACardCollection, Contents);
	DOREPLIFETIME(ACardCollection, Cards);
}
