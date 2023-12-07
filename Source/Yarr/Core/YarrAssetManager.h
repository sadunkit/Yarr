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
	static UYarrAssetManager& Get();
	virtual void PostInitProperties() override;

	UFUNCTION(BlueprintCallable, Category = "Yarr")
	static void GetAssetTypeInfo(TArray<FName>& OutAssetTypeNames);
	
#pragma region Pirates
	/*
	 *	This will load all the body parts that are tagged as accessories. Blocking call.
	 */
	TArray<const USkeletalMesh*> GetBodyPartsToAttach();
#pragma endregion
	
#if ENABLE_DRAW_DEBUG
	void DisplayDebug(UCanvas* Canvas);
#endif
};
