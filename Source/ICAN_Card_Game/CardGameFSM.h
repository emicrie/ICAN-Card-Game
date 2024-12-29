// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardGameFSM.generated.h"

class ACardFSMState;

UCLASS()
class ICAN_CARD_GAME_API ACardGameFSM : public AActor
{
	GENERATED_BODY()
	
public:	
	ACardGameFSM();

	~ACardGameFSM();

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "States")
	ACardFSMState* CurrentState = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States")
	ACardFSMState* NextState = nullptr;

	UFUNCTION(BlueprintCallable)
	void ChangeState(FString StateName, bool PlayTransition = true);
	UFUNCTION(BlueprintCallable)
	void SetNextState(FString Dest);
	UFUNCTION(BlueprintCallable)
	void GoToNextState();
	UFUNCTION(BlueprintCallable)
	void DebugCurrentState();

protected:
	UFUNCTION(BlueprintCallable)
	void ChangeStateTo(ACardFSMState* Dest, bool PlayTransition = true);
	UFUNCTION(BlueprintCallable)
	ACardFSMState* GetState(const FString StateName);

public:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "States")
	TArray<TSubclassOf<ACardFSMState >> States;

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
