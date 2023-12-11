// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

#include "PirateSpawnAction.h"

#include "PirateCharacter.h"
#include "Yarr/YarrLogChannels.h"
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
		
		NewPirate->BodyPartsToAttach = GetBodyPartsToAttach();

		NewPirate->FinishSpawning(FTransform::Identity, true);
	}
}

void UPirateSpawnAction_HoldOnToAccessorySet::BeginPlay(const TSubclassOf<ACharacter> InPirateClass)
{
	Super::BeginPlay(InPirateClass);

	UYarrAssetManager::Get().LoadViaPrimaryAssetList(FAccessorySetLoadedDelegate::CreateWeakLambda(this, [this](const FAccessorySet& InAccessorySet)
	{
		UE_LOG(LogYarr, Log, TEXT("Accessory Set Loaded"));

		AccessorySet = MakeShared<FAccessorySet>(InAccessorySet);
	}));
}

void UPirateSpawnAction_HoldOnToAccessorySet::Tick(float DeltaSeconds)
{
	if (AccessorySet.IsValid())
	{
		Super::Tick(DeltaSeconds);
	}
}

TArray<const USkeletalMesh*> UPirateSpawnAction_HoldOnToAccessorySet::GetBodyPartsToAttach() const
{
	if (AccessorySet.IsValid())
	{
		return AccessorySet->AccessoryParts;
	}

	return {};
}
