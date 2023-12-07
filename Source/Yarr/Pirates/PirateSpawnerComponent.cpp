// Fill out your copyright notice in the Description page of Project Settings.


#include "PirateSpawnerComponent.h"

#include "PirateCharacter.h"
#include "PirateSpawnAction.h"

UPirateSpawnerComponent::UPirateSpawnerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bWantsInitializeComponent = true;
	PrimaryComponentTick.bCanEverTick = true;
	SetTickGroup(TG_DuringPhysics);
}

void UPirateSpawnerComponent::InitializeComponent()
{
	Super::InitializeComponent();
	
	if (PirateClass == nullptr)
	{
		PirateClass = APirateCharacter::StaticClass();
	}
}

void UPirateSpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
	
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
