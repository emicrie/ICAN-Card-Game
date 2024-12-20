// Fill out your copyright notice in the Description page of Project Settings.


#include "CardCollectionsManager.h"

UCardCollectionsManager* UCardCollectionsManager::Instance = nullptr;

// Sets default values for this component's properties
UCardCollectionsManager::UCardCollectionsManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UCardCollectionsManager* UCardCollectionsManager::GetInstance()
{
	return Instance;
}

// Called when the game starts
void UCardCollectionsManager::BeginPlay()
{
	Super::BeginPlay();

	if(!Instance)
	{
		Instance = this;
		// Ensure the instance is not garbage collected
		Instance->AddToRoot();
	}

}

void UCardCollectionsManager::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	if(Instance)
	{
		Instance->RemoveFromRoot();
		Instance = nullptr;
	}
}

