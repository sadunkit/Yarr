// Fill out your copyright notice in the Description page of Project Settings.


#include "PirateSpawnerComponent.h"

#include "PirateCharacter.h"
#include "PirateSpawnAction.h"
#include "GameFramework/Character.h"

UPirateSpawnerComponent::UPirateSpawnerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UPirateSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (PirateClass == nullptr)
	{
		PirateClass = APirateCharacter::StaticClass();
	}
	
	for (const auto& Action : SpawnerActions)
	{
		Action->SetPawnClass(PirateClass);
	}
}

void UPirateSpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (const auto& Action : SpawnerActions)
	{
		Action->Tick(DeltaTime);
	}
}
