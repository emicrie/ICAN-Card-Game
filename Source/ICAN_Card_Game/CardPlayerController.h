// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CardPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACardPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputMappingContext* InputMappingContext;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnClickBP();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCardCollectionsManager* CollectionManager = nullptr;

	UFUNCTION()
	void OnClick();	
};
