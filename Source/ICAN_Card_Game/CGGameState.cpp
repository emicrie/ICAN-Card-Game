// Fill out your copyright notice in the Description page of Project Settings.
#include "CGGameState.h"

#define CHECK_SUBCLASS_SET(x) checkf(x, TEXT("The variable %s hasn't been set. It is required to set its value in editor before starting the game!"));

void ACGGameState::BeginPlay()
{
	Super::BeginPlay();
	OnStart();
}
