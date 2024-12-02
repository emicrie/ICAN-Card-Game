// Fill out your copyright notice in the Description page of Project Settings.


#include "CardPlayerController.h"
#include "CardCollectionsManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"

void ACardPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	CollectionManager = UCardCollectionsManager::GetInstance();
}

void ACardPlayerController::OnClick()
{
	OnClickBP();
}
