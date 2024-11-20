// Fill out your copyright notice in the Description page of Project Settings.


#include "CardSlotComponent.h"
#include "CardCollection.h"
#include "CardCollectionsManager.h"
#include "PlayedCardMat.h"
#include "CGGameState.h"
#include "ReplicatedPlayedCards.h"
#include "ReplicatedCardData.h"
#include "ReplicatedHand.h"

UCardSlotComponent::UCardSlotComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCardSlotComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CollectionManager = UCardCollectionsManager::GetInstance();
}

void UCardSlotComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UCardSlotComponent::Interact(UReplicatedCardCollection*& InstigatorCollection, UReplicatedCardData*& Data) const
{
	ACGGameState* GameState = Cast<ACGGameState>(GetWorld()->GetGameState());
	if (GameState)
	{
		bool bTransferSucceeded = false;

		UReplicatedPlayedCards* PlayedMat = GameState->PlayedCards;

		//We swap with card with hand
		checkf((GameState->PlayedCards), TEXT("Collection is expected to be a played card mat"))
			if (PlayedMat->Elements[ID])
			{
				//TODO: These assignations are hard coded, we should probably find a smarter way to assure it's a hand->slot situation
				PlayedMat->Elements[ID]->Status = EReplicatedCardStatus::IN_HAND;
				Data->Status = EReplicatedCardStatus::IN_SLOT;

				UReplicatedCardCollectionManager* Mng = GameState->CollectionManager;
				bTransferSucceeded = Mng->SwapCard(PlayedMat->Elements[ID], InstigatorCollection->Elements[InstigatorCollection->Elements.IndexOfByKey(Data)]);
				
				//Mng->Hand->UpdateCollectionVisuals();
				PlayedMat->UpdateCollectionVisuals();

				//CollectionManager->DeselectHand();

				//if (PlayedMat->IsCollectionFull())
				//{
				//	UE_LOG(LogTemp, Warning, TEXT("The played mat has been filled!"));
				//	if (Cast<APlayedCardMat>(OwnerCollection))
				//	{
				//		Cast<APlayedCardMat>(OwnerCollection)->ValidateFilledMat();
				//	}
				//}

			}
			//We transfer card in hand
			//else
			//{
			//	Card->Status = ECardStatus::IN_SLOT;
			//	bTransferSucceeded = CollectionManager->MoveBetweenCollections(CollectionManager->Hand, OwnerCollection, Card, ID);
			//	CollectionManager->DeselectHand();
			//	OwnerCollection->UpdateCollectionVisuals();
			//}
		return bTransferSucceeded;
	}
	return false;
}

bool UCardSlotComponent::Interact(ACard*& Card) const
{
	ACardCollection* OwnerCollection = Cast<ACardCollection>(GetOwner());

	if(OwnerCollection)
	{
		bool bTransferSucceeded = false;
		
		//We swap with card with hand
		checkf(Cast<APlayedCardMat>(OwnerCollection), TEXT("Collection is expected to be a played card mat"))
		if(OwnerCollection->Cards[ID])
		{
			//TODO: These assignations are hard coded, we should probably find a smarter way to assure it's a hand->slot situation
			OwnerCollection->Cards[ID]->Status = ECardStatus::IN_HAND;
			Card->Status = ECardStatus::IN_SLOT;

			bTransferSucceeded = CollectionManager->SwapCard(OwnerCollection->Cards[ID], CollectionManager->Hand->Cards[CollectionManager->Hand->Cards.IndexOfByKey(Card)]);
			CollectionManager->Hand->UpdateCollectionVisuals();
			OwnerCollection->UpdateCollectionVisuals();
			CollectionManager->DeselectHand();

			if(OwnerCollection->IsCollectionFull())
			{
				UE_LOG(LogTemp, Warning, TEXT("The played mat has been filled!"));
				if(Cast<APlayedCardMat>(OwnerCollection))
				{
					Cast<APlayedCardMat>(OwnerCollection)->ValidateFilledMat();
				}
			}
			
		}
		//We transfer card in hand
		else
		{
			Card->Status = ECardStatus::IN_SLOT;
			bTransferSucceeded = CollectionManager->MoveBetweenCollections(CollectionManager->Hand, OwnerCollection, Card, ID);
			CollectionManager->DeselectHand();
			OwnerCollection->UpdateCollectionVisuals();
		}
		return bTransferSucceeded;
		
	}
	return false;
}
