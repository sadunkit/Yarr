// Fill out your copyright notice in the Description page of Project Settings.


#include "PirateSpawnAction.h"

#include "PirateCharacter.h"

void UPirateSpawnAction_DefaultSpawn::Tick(float DeltaSeconds)
{
	TimeSinceLastSpawn += DeltaSeconds;

	if (TimeSinceLastSpawn > SpawnDelay)
	{
		TimeSinceLastSpawn = 0.0f;

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.bDeferConstruction = true;
		
		APirateCharacter* NewPirate = GetWorld()->SpawnActor<APirateCharacter>(PirateClass, FVector::Zero(), FRotator::ZeroRotator, SpawnParams);


		NewPirate->BodyPartsToAttach = {};

		NewPirate->FinishSpawning(FTransform::Identity, true);
	}
}
