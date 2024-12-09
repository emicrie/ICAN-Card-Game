// Fill out your copyright notice in the Description page of Project Settings.


#include "CardCollection.h"

#include "CardGameMode.h"
#include "CGGameState.h"
#include "CGPlayerState.h"
#include "Kismet/GameplayStatics.h"
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
	OnStart();
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
	Contents.Reserve(MaxCapacity);
	Contents.Init(-1, MaxCapacity);
	Cards.Reserve(MaxCapacity);
	Cards.AddDefaulted(MaxCapacity);
}

void ACardCollection::BindDynamicsToDelegate()
{
	//TODO: This is disgusting and hard coded, but I'm too tired and got no time at this point

	if(HasAuthority())
	{
		//ACardGameMode* GameMode = Cast<ACardGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		//checkf(GameMode, TEXT("Game Mode is null"));
		//
		//if (Cast<ICardCollectionInterface>(GameMode->Deck)->GetCollectionType() == CollectionType)
		//{
		//	UE_LOG(LogTemp, Error, TEXT("Found a fitting interface for deck"));
		//	Cast<ICardCollectionInterface>(GameMode->Deck)->GetOnCollectionChanged().AddDynamic(this, &ACardCollection::MatchVisualsToData);
		//}
		//
		//if (Cast<ICardCollectionInterface>(GameMode->PlayedCards)->GetCollectionType() == CollectionType)
		//{
		//	UE_LOG(LogTemp, Error, TEXT("Found a fitting interface for played cards"));
		//	Cast<ICardCollectionInterface>(GameMode->PlayedCards)->GetOnCollectionChanged().AddDynamic(this, &ACardCollection::MatchVisualsToData);
		//}
	}

	int Index = 0;
	ACGGameState* GameState = Cast<ACGGameState>(GetWorld()->GetGameState());
	for (APlayerState* PlState : GameState->PlayerArray)
	{
		//ACGPlayerState* State = Cast<ACGPlayerState>(PlState);
		//if (State != nullptr && (Cast<ICardCollectionInterface>(State->Hand)->GetCollectionType() == CollectionType))
		//{
		//	UE_LOG(LogTemp, Error, TEXT("Found a fitting interface for hand of player %i"), Index);
		//	State->Hand->GetOnCollectionChanged().AddDynamic(this, &ACardCollection::MatchVisualsToData);
		//}
		//Index++;
	}
}

bool ACardCollection::AddCard(int CardID, int PositionToMoveAt)
{
	if (bInfiniteCapacity || Contents.Num() < MaxCapacity)
	{
		AddCardBP(CardID, PositionToMoveAt);
		Contents.Insert(CardID, PositionToMoveAt);
		UpdateCollectionVisuals();
		return true;
	}
	return false;
}

bool ACardCollection::SetCard(int CardPosInList, const int Index)
{
	Contents[CardPosInList] = Index;

	//if(Index < MaxCapacity)
	//{
	//	if(Cards[CardPosInList] != nullptr)
	//	{
	//		Cards[Index] = Cards[CardPosInList];
	//		Cards[Index]->bIsCardSet = true;
	//	}
	//	return true;
	//}
	
	return true;
}

bool ACardCollection::RemoveCard(int CardPosInList)
{
	if (Contents.Num() > 0 && CardPosInList < Contents.Num())
	{
		RemoveCardBP(CardPosInList);
		Contents.RemoveAt(CardPosInList);
		//UE_LOG(LogTemp, Warning, TEXT("Number of cards in caller's deck: %d"), Contents.Num());
		UpdateCollectionVisuals();
		return true;
	}
	return false;
}

void ACardCollection::UpdateCollectionVisuals()
{
	UpdateCollectionVisualsToMatchCollectionData(this);
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

	DOREPLIFETIME(ACardCollection, Contents);
	DOREPLIFETIME(ACardCollection, Cards);
}
