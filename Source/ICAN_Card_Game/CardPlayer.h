// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CardPlayer.generated.h"

UCLASS()
class ICAN_CARD_GAME_API ACardPlayer : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

public:
	// Sets default values for this pawn's properties
	ACardPlayer();

	UPROPERTY(EditAnywhere)
	class UCameraComponent* PlayerCamera = nullptr;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ClickAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class ACardPlayerController* Controller = nullptr;

	UFUNCTION(BlueprintCallable)
	void OnClick();

	UFUNCTION(BlueprintImplementableEvent)
	void OnClickBP();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCardCollectionsManager* CollectionManager = nullptr;
};
