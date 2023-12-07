// Fill out your copyright notice in the Description page of Project Settings.


#include "YarrAssetManager.h"

#include "Engine/Canvas.h"
#include "Yarr/YarrLogChannels.h"

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
