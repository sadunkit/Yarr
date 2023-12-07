// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PirateSpawnerComponent.h"
#include "UObject/Object.h"
#include "Yarr/YarrLogChannels.h"
#include "PirateSpawnAction.generated.h"

/**
 * 
 */
UCLASS(Abstract, EditInlineNew, DefaultToInstanced)
class YARR_API UPirateSpawnAction : public UObject
{
	GENERATED_BODY()
public:

	virtual void SetPawnClass(const TSubclassOf<ACharacter> InPirateClass)
	{
		PirateClass = InPirateClass;

		UPirateSpawnerComponent* OuterComponent = Cast<UPirateSpawnerComponent>(GetOuter());

		checkf(OuterComponent, TEXT("Pirate Spawn Action must be owned by a Pirate Spawner Component"));

		PirateSpawnerComponent = OuterComponent;
	};

	virtual void Tick(float DeltaSeconds)
	{

	};

protected:
	TSubclassOf<ACharacter> PirateClass;

	UPROPERTY()
	TObjectPtr<UPirateSpawnerComponent> PirateSpawnerComponent;
};

UCLASS(meta=(DisplayName="Default Spawn"))
class YARR_API UPirateSpawnAction_DefaultSpawn : public UPirateSpawnAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Pirate")
	float SpawnDelay = 1.0f;

	virtual void Tick(float DeltaSeconds) override;

private:
	float TimeSinceLastSpawn = 0.0f;
};
