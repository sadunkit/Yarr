// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PirateSpawnerComponent.generated.h"

class UPirateSpawnAction;
class APirateCharacter;

UCLASS(meta=(BlueprintSpawnableComponent))
class YARR_API UPirateSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPirateSpawnerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// List of actions to perform as this round is initializing, starting and ending
	UPROPERTY(EditAnywhere, Instanced, Category="Pirates")
	TArray<TObjectPtr<UPirateSpawnAction>> SpawnerActions;

	UPROPERTY(EditDefaultsOnly, Category="Pirates")
	TSubclassOf<APirateCharacter> PirateClass;
};
