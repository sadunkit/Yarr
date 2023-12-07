// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PirateSpawnerComponent.generated.h"

UCLASS(meta=(BlueprintSpawnableComponent))
class YARR_API UPirateSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPirateSpawnerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// List of actions to perform as this round is initializing, starting and ending
	UPROPERTY(EditAnywhere, Instanced, Category="Pirates")
	TArray<TObjectPtr<class UPirateSpawnAction>> SpawnerActions;

	UPROPERTY(EditAnywhere, Category="Pirates")
	TSubclassOf<ACharacter> PirateClass;
};
