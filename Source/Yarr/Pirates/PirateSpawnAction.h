// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

#pragma once

#include "CoreMinimal.h"
#include "PirateSpawnerComponent.h"
#include "UObject/Object.h"
#include "Yarr/Core/YarrAssetManager.h"
#include "PirateSpawnAction.generated.h"

struct FAccessorySet;
/**
 * 
 */
UCLASS(Abstract, EditInlineNew, DefaultToInstanced)
class YARR_API UPirateSpawnAction : public UObject
{
	GENERATED_BODY()
public:

	virtual void BeginPlay(const TSubclassOf<ACharacter> InPirateClass)
	{
		PirateClass = InPirateClass;

		UPirateSpawnerComponent* OuterComponent = Cast<UPirateSpawnerComponent>(GetOuter());

		checkf(OuterComponent, TEXT("Pirate Spawn Action must be owned by a Pirate Spawner Component"));

		PirateSpawnerComponent = OuterComponent;
	};

	virtual void Tick(float DeltaSeconds)
	{

	};

	virtual TArray<const USkeletalMesh*> GetBodyPartsToAttach() const
	{
		return UYarrAssetManager::Get().LoadPiratePartMeshesAndJustPassThemAlong();
	};

protected:
	TSubclassOf<ACharacter> PirateClass;

	UPROPERTY()
	TObjectPtr<UPirateSpawnerComponent> PirateSpawnerComponent;
};

/**
 *  This is a Pirate Spawn Action that will spawn a pirate every SpawnDelay seconds
 *  Uses the default GetBodyPartsToAttach implementation to load the SkeletalMeshes without any real thought;
 *  and just passes them along to the spawned pirate.
 *
 *  I personally think this is the cleanest way to do this, but I'm open to suggestions.
 */
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


/**
 *  This is a Pirate Spawn Action that will hold on to the FAccessorySet in a TSharedPtr
 */
UCLASS(meta=(DisplayName="Hold on to Accessory Set"))
class YARR_API UPirateSpawnAction_HoldOnToAccessorySet : public UPirateSpawnAction_DefaultSpawn
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay(const TSubclassOf<ACharacter> InPirateClass) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual TArray<const USkeletalMesh*> GetBodyPartsToAttach() const override;
	
	TSharedPtr<const FAccessorySet> AccessorySet;
};
