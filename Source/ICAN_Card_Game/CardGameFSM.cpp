// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameFSM.h"
#include "CardGameState.h"
#include "Net/UnrealNetwork.h"

ACardGameFSM::ACardGameFSM()
{
}

ACardGameFSM::~ACardGameFSM()
{
}

void ACardGameFSM::ChangeStateTo(ACardFSMState* Dest, bool PlayTransition)
{
	if (CurrentState && PlayTransition)
	{
		CurrentState->EndDelegate();
	}
	CurrentState = Dest;
	if (PlayTransition) {
		CurrentState->StartDelegate();
	}
}

void ACardGameFSM::DebugCurrentState()
{
	//UE_LOG(LogTemp, Warning, TEXT("Current State: %s"), *CurrentState->Name);
}

void ACardGameFSM::SetNextState(FString Dest)
{
	ACardFSMState* St = GetState(Dest);
	if (St != nullptr)
	{
		NextState = St;
	}
}

void ACardGameFSM::GoToNextState()
{
	ChangeStateTo(NextState, true);
}

void ACardGameFSM::ChangeState(FString StateName, bool PlayTransition)
{
	ACardFSMState* St = GetState(StateName);
	if (St != nullptr)
	{
		FString Dummy = "No state";
		UE_LOG(LogTemp, Warning, TEXT("Changing State from : % s To : % s"), CurrentState ? *CurrentState->Name : *Dummy, *StateName);
		ChangeStateTo(St, PlayTransition);
	}
	else {

	}
}

ACardFSMState* ACardGameFSM::GetState(const FString StateName)
{
	for (UClass* St : States)
	{
		ACardFSMState* State = Cast<ACardFSMState>(St);
		if (State != nullptr)
		{
			if (State->Name == StateName) {
				return State;
			}
		}

	}
	UE_LOG(LogTemp, Warning, TEXT("State %s Not found!"), *StateName);
	return nullptr;
}

void ACardGameFSM::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACardGameFSM, CurrentState);
}
