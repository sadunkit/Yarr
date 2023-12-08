// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"

#include "YarrAssetManager.generated.h"

USTRUCT()
struct FAccessorySet
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TObjectPtr<const USkeletalMesh>> AccessoryParts;
};

DECLARE_DELEGATE_OneParam(FAccessorySetLoadedDelegate, const FAccessorySet&);

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
	 *	This will load all the body parts that are tagged as accessories.
	 *	And return the SkeletalMeshes after loading them.
	 *	Blocking call.
	 */
	TArray<const USkeletalMesh*> LoadPiratePartMeshesAndJustPassThemAlong();

	/*
	 *	This will load all the body parts that are tagged as accessories.
	 *	And call the delegate with the SkeletalMeshes after loading them.
	 *	Async call.
	 */
	void LoadViaPrimaryAssetList(const FAccessorySetLoadedDelegate& OnLoadComplete);

private:
	/*
	 *	 Gets the asset data for all the assets of PiratePartData Tagged with Accessory
	 */
	TArray<FAssetData> GetAccessoryAssetData() const;
#pragma endregion
	
#if ENABLE_DRAW_DEBUG
public:
	void DisplayDebug(UCanvas* Canvas);
#endif
};
