// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

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
