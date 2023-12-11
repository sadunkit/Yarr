// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "PiratePartData.generated.h"

USTRUCT(BlueprintType)
struct FPiratePartUIData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pirate Part")
	FText Description;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pirate Part", meta=(AssetBundles="UI"))
	TSoftObjectPtr<UTexture2D> Icon;
};

/**
 * 
 */
UCLASS()
class YARR_API UPiratePartData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pirate Part", AssetRegistrySearchable)
	FGameplayTag PartTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pirate Part")
	FGameplayTagContainer DetailTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pirate Part", meta=(AssetBundles="Gameplay"))
	TSoftObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pirate Part")
	FPiratePartUIData UIData;
};
