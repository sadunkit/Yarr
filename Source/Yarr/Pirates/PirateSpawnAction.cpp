// Fill out your copyright notice in the Description page of Project Settings.


#include "PirateSpawnAction.h"

#include "PirateCharacter.h"
#include "Yarr/Core/YarrAssetManager.h"

void UPirateSpawnAction_DefaultSpawn::Tick(float DeltaSeconds)
{
	TimeSinceLastSpawn += DeltaSeconds;

	if (TimeSinceLastSpawn > SpawnDelay)
	{
		TimeSinceLastSpawn = 0.0f;

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		SpawnParams.bDeferConstruction = true;
		
		APirateCharacter* NewPirate = GetWorld()->SpawnActor<APirateCharacter>(PirateClass, FVector{ 0, 0, 200}, FRotator::ZeroRotator, SpawnParams);
		
		NewPirate->BodyPartsToAttach = UYarrAssetManager::Get().GetBodyPartsToAttach();

		NewPirate->FinishSpawning(FTransform::Identity, true);
	}
}
