// Fill out your copyright notice in the Description page of Project Settings.


#include "CardPlayer.h"
#include "Camera/CameraComponent.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "CardPlayerController.h"

//TODO: References to such elements should be put in a manager
#include "DeckActor.h"
#include "DiscardedDeckActor.h"
#include "Card.h"
#include "CardHand.h"

// Sets default values
ACardPlayer::ACardPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));

}

// Called when the game starts or when spawned
void ACardPlayer::BeginPlay()
{
	Super::BeginPlay();
	Controller = Cast<ACardPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	Controller->bShowMouseCursor = true;
	Controller->DefaultMouseCursor = EMouseCursor::Crosshairs;
	
}

// Called every frame
void ACardPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACardPlayer::OnClick()
{
	//TODO: This is currently highly complicated and inefficient for nothing on top of adding problematics due to poor architecture. This will have to be refactorized.
	if (Controller)
	{
		FVector2D MousePosition;
		Controller->GetMousePosition(MousePosition.X, MousePosition.Y);

		FVector	WorldPosition;
		FVector WorldDirection;

		UGameplayStatics::DeprojectScreenToWorld(Controller, MousePosition, WorldPosition, WorldDirection);
		FHitResult HitResult;

		//DrawDebugLine(GetWorld(), WorldPosition, WorldDirection * 10000, FColor::White, true);
		GetWorld()->LineTraceSingleByChannel(HitResult, WorldPosition, WorldDirection * 10000,
			ECollisionChannel::ECC_GameTraceChannel1);

		if (HitResult.bBlockingHit)
		{
			ADeckActor* Deck = Cast<ADeckActor>(HitResult.GetActor());
			if (Deck)
			{
				Deck->DrawCard(1);
			}
			return;
		}

		GetWorld()->LineTraceSingleByChannel(HitResult, WorldPosition, WorldDirection * 10000,
			ECollisionChannel::ECC_GameTraceChannel2);

		if (HitResult.bBlockingHit)
		{
			ACard* Card = Cast<ACard>(HitResult.GetActor());
			if (Card)
			{
				TArray<AActor*> dest;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADiscardedDeckActor::StaticClass(), dest);
				ADiscardedDeckActor* DiscDeck= Cast<ADiscardedDeckActor>(dest[0]);

				UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACardHand::StaticClass(), dest);
				ACardHand* Hand = Cast<ACardHand>(dest[0]);

				Card->PlayCard(DiscDeck, Hand);
			}
		}

	}
}

// Called to bind functionality to input
void ACardPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Interacting
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Triggered, this, &ACardPlayer::OnClick);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

