// Fill out your copyright notice in the Description page of Project Settings.


#include "CardCollection.h"
#include "ReplicatedCardData.h"
#include "CardCollectionsManager.h"
#include "Kismet/GameplayStatics.h"
#include "CGGameState.h"
#include "CGPlayerState.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ACardCollection::ACardCollection()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACardCollection::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(InitTimer, this, &ACardCollection::BindDynamicsToDelegate, 0.4f, false);
}

void ACardCollection::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Cards.Reset();
}

// Called every frame
void ACardCollection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACardCollection::InitCollection()
{
	Cards.AddDefaulted(MaxCapacity);
}

void ACardCollection::BindDynamicsToDelegate()
{
	//TODO: This is disgusting and hard coded, but I'm too tired and got no time at this point

	ACGGameState* GameState = Cast<ACGGameState>(GetWorld()->GetGameState());

	if (Cast<ICardCollectionInterface>(GameState->Deck)->GetCollectionType() == CollectionType)
	{
		UE_LOG(LogTemp, Error, TEXT("Found a fitting interface for deck"));
		Cast<ICardCollectionInterface>(GameState->Deck)->GetOnCollectionChanged().AddDynamic(this, &ACardCollection::MatchVisualsToData);
	}

	if (Cast<ICardCollectionInterface>(GameState->PlayedCards)->GetCollectionType() == CollectionType)
	{
		UE_LOG(LogTemp, Error, TEXT("Found a fitting interface for played cards"));
		Cast<ICardCollectionInterface>(GameState->PlayedCards)->GetOnCollectionChanged().AddDynamic(this, &ACardCollection::MatchVisualsToData);
	}

	int Index = 0;
	for (APlayerState* PlState : GameState->PlayerArray)
	{
		ACGPlayerState* State = Cast<ACGPlayerState>(PlState);
		if (State != nullptr && (Cast<ICardCollectionInterface>(State->Hand)->GetCollectionType() == CollectionType))
		{
			UE_LOG(LogTemp, Error, TEXT("Found a fitting interface for hand of player %i"), Index);
			State->Hand->GetOnCollectionChanged().AddDynamic(this, &ACardCollection::MatchVisualsToData);
		}
		Index++;
	}
}

bool ACardCollection::AddCard(ACard* Card)
{
	Card->bIsCardSet = true;
	return true;
}

bool ACardCollection::SetCard(ACard* Card, const int Index)
{
	if(Index < MaxCapacity)
	{
		if(Card != nullptr)
		{
			Cards[Index] = Card;
			Cards[Index]->bIsCardSet = true;
		}
		return true;
	}
	
	return false;
}

bool ACardCollection::RemoveCard(ACard* Card)
{
	return true;
}

void ACardCollection::UpdateCollectionVisuals()
{
	
}

void ACardCollection::MatchVisualsToData(const UReplicatedCardCollection* Collection)
{
	UpdateCollectionVisualsToMatchCollectionData(Collection);
}

bool ACardCollection::Shuffle()
{
	return true;
}

bool ACardCollection::IsCollectionFull()
{
	return Cards.Num() == MaxCapacity;
}

void ACardCollection::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACardCollection, Cards);
}
