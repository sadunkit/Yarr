// Fill out your copyright notice in the Description page of Project Settings.


#include "YarrAssetManager.h"

#include "Yarr/YarrLogChannels.h"

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
