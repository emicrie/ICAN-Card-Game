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

bool UCardCollectionsManager::MoveBetweenCollections(ACardCollection* A, ACardCollection* B, int CardIDInList, const int IndexToMoveAt, ACGPlayerState* PlayerState)
{
	MoveBetweenCollectionsBP(A, B, CardIDInList, IndexToMoveAt);
	return true;
	//bool Result = false;
	//bool IsAnyCollectionInvalid = A->Contents.Num() <= 0 || (!B->bInfiniteCapacity && (B->Contents.Num() >= B->MaxCapacity));
	//if (IsAnyCollectionInvalid) { return false; }
	//
	//if (A && B && CardIDInList >= 0)
	//{
	//	int Value = A->Contents[CardIDInList];
	//	Result |= A->RemoveCard(CardIDInList);
	//	if (IndexToMoveAt < 0)
	//	{
	//		Result |= Result && B->AddCard(Value);
	//	}
	//	else
	//	{
	//		Result = Result && B->SetCard(CardIDInList, IndexToMoveAt);
	//	}
	//	A->UpdateCollectionVisuals();
	//	B->UpdateCollectionVisuals();
	//}
	//return Result;
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

