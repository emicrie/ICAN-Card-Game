// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	EnemyMesh->SetupAttachment(RootComponent);

	TextComponentHealth = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Health Text Render"));
	TextComponentHealth->SetupAttachment(RootComponent);
	TextComponentHealth->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	TextComponentHealth->WorldSize = 56.0f;
	TextComponentHealth->SetWorldLocation(FVector(0, 0, 250));
	TextComponentHealth->SetText(FText::FromString("-1"));

	TextComponentName = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Name Text Render"));
	TextComponentName->SetupAttachment(RootComponent);
	TextComponentName->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	TextComponentName->WorldSize = 56.0f;
	TextComponentName->SetWorldLocation(FVector(0, 0, 300));
	TextComponentName->SetText(FText::FromString("Name"));

	SetReplicates(true);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::PostEditChangeProperty(FPropertyChangedEvent& e)
{
	FName PropertyName = (e.Property != NULL) ? e.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AEnemy, Name))
	{
		TextComponentName->SetText(Name);
	}
	else if (PropertyName == GET_MEMBER_NAME_CHECKED(AEnemy, Health))
	{
		FString HealthValueStr = FString::FromInt(Health);
		TextComponentHealth->SetText(FText::FromString(HealthValueStr));
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

