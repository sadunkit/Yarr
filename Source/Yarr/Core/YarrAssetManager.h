// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "YarrAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class YARR_API UYarrAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

	UFUNCTION(BlueprintCallable, Category = "Yarr")
	static void GetAssetTypeInfo(TArray<FName>& OutAssetTypeNames);
};
