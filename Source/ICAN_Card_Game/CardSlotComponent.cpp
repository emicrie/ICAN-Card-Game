// Fill out your copyright notice in the Description page of Project Settings.


#include "CardSlotComponent.h"
#include "CardCollection.h"
#include "CardCollectionsManager.h"
#include "PlayedCardMat.h"

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
