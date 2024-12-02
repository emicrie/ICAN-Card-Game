// Fill out your copyright notice in the Description page of Project Settings.


#include "CGPlayerState.h"

void ACGPlayerState::BeginPlay()
{
	Super::BeginPlay();
	//Hand = NewObject<UReplicatedHand>(this, HandCollectionToUse.GetDefaultObject()->GetClass());
	
	//PlayerNumber++;	
	//ID = PlayerNumber;

	OnStart();
}
