// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "YarrHUD.generated.h"

/**
 * 
 */
UCLASS()
class YARR_API AYarrHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void ShowDebugInfo(float& YL, float& YPos) override;
};
