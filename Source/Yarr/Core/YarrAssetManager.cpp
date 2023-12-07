// Fill out your copyright notice in the Description page of Project Settings.


#include "YarrAssetManager.h"

#include "GameplayTagContainer.h"
#include "Engine/Canvas.h"
#include "Yarr/YarrGameplayTags.h"
#include "Yarr/YarrLogChannels.h"
#include "Yarr/DataAssets/PiratePartData.h"

UYarrAssetManager& UYarrAssetManager::Get()
{
	check(GEngine);

	if (UYarrAssetManager* Singleton = Cast<UYarrAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}

	UE_LOG(LogYarr, Fatal, TEXT("Invalid AssetManagerClassName in DefaultEngine.ini.  It must be set to LyraAssetManager!"));

	// Fatal error above prevents this from being called.
	return *NewObject<UYarrAssetManager>();
}

void UYarrAssetManager::PostInitProperties()
{
	Super::PostInitProperties();

	UE_LOG(LogYarr, Log, TEXT("YarrAssetManager PostInitProperties"));
}

void UYarrAssetManager::GetAssetTypeInfo(TArray<FName>& OutAssetTypeNames)
{
	TArray<FPrimaryAssetTypeInfo> AssetTypeInfos;
	Get().GetPrimaryAssetTypeInfoList(AssetTypeInfos);

	for (const FPrimaryAssetTypeInfo& AssetTypeInfo : AssetTypeInfos)
	{
		OutAssetTypeNames.Add(AssetTypeInfo.PrimaryAssetType);
	}
}

#pragma region Pirates
namespace Pirates
{
	// this should just be a static member of UYarrAssetManager
	const FPrimaryAssetType PiratePartDataType = FPrimaryAssetType("PiratePartData");
}

TArray<const USkeletalMesh*> UYarrAssetManager::GetBodyPartsToAttach()
{
	TArray<const USkeletalMesh*> Meshes = {};

	TArray<FAssetData> AssetDataList;
	GetPrimaryAssetDataList(Pirates::PiratePartDataType, AssetDataList);

	const auto FilteredAssets = AssetDataList.FilterByPredicate([] (const FAssetData& AssetData)
	{
		if (const FAssetDataTagMapSharedView::FFindTagResult TagValue = AssetData.TagsAndValues.FindTag(GET_MEMBER_NAME_CHECKED(UPiratePartData, PartTag)); TagValue.IsSet())
		{
			FGameplayTag Tag;
			Tag.FromExportString(TagValue.GetValue());
			
			return Tag.MatchesTag(YarrGameplayTags::Pirate_BodyPart_Accessory);
		}
		return false;
	});
	
	if (const int32 FilteredAssetsSize = FilteredAssets.Num(); FilteredAssetsSize > 0)
	{
		//	TArray<FPrimaryAssetId> AssetsToLoad;
		//  AssetsToLoad.Reserve(FilteredAssetsSize);
		//  AssetsToLoad.Add(AssetData.GetPrimaryAssetId());
		//  TSharedPtr<FStreamableHandle> Handle = ChangeBundleStateForPrimaryAssets(AssetsToLoad, {"Gameplay"}, {});
		
		for (const FAssetData& AssetData : FilteredAssets)
		{
			// Loads the asset synchronously
			if (const UPiratePartData* PiratePartData = Cast<UPiratePartData>(AssetData.GetAsset()))
			{
				// the mesh still needs to be loaded separately
				// this same operation can be done asynchronously using the AsyncMixin in Lyra.
				Meshes.Add(PiratePartData->SkeletalMesh.LoadSynchronous());
			}
		}
	}
	
	return Meshes;
}
#pragma endregion

#if ENABLE_DRAW_DEBUG
void UYarrAssetManager::DisplayDebug(UCanvas* Canvas)
{
	// TODO: UEnhancedInputUserSettings::ShowDebugInfo is a good example of how to do this
	
	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;
	
	DisplayDebugManager.SetFont(GEngine->GetSmallFont());
	DisplayDebugManager.SetDrawColor(FColor::Yellow);
	DisplayDebugManager.DrawString(TEXT("YARR ASSET MANAGER"));

	DisplayDebugManager.SetFont(GEngine->GetSmallFont());
	DisplayDebugManager.SetDrawColor(FColor::Yellow);
	DisplayDebugManager.DrawString(TEXT("TODO AFTER THIS POINT"));
}
#endif
