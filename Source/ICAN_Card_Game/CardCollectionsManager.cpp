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

void UCardCollectionsManager::DeselectHand()
{
	for(int i = 0; i < Hand->Cards.Num(); ++i)
	{
		Hand->Cards[i]->bIsCardSelected = false;
	}
	SelectedCard = nullptr;
}

void UCardCollectionsManager::SelectCard(ACard* Card)
{
	if(Card)
	{
		SelectedCard = Card;
		Card->bIsCardSelected = true;
	}
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


// Called every frame
void UCardCollectionsManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UCardCollectionsManager::MoveBetweenCollections(ACardCollection* A, ACardCollection* B, ACard* Card, const int IndexToMoveAt)
{
	bool Result = false;
	bool IsAnyCollectionInvalid = A->Cards.Num() <= 0 || (!B->bInfiniteCapacity && (B->Cards.Num() > B->MaxCapacity));
	if (IsAnyCollectionInvalid) { return false; }

	if (A && B && Card)
	{
		Result |= A->RemoveCard(Card);
		if (IndexToMoveAt < 0)
		{
			Result = Result && B->AddCard(Card);
		}
		else
		{
			Result = Result && B->SetCard(Card, IndexToMoveAt);
		}
		A->UpdateCollectionVisuals();
		B->UpdateCollectionVisuals();
	}
	return Result;
}

bool UCardCollectionsManager::SwapCard(ACard*& CardA, ACard*& CardB)
{
	if(CardA && CardB)
	{
		CardA->bIsCardSet = false;
		CardB->bIsCardSet = true;
		::Swap(CardA, CardB);
		return true;
	}
	return false;
}

