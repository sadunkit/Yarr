// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

#include "YarrHUD.h"

#include "Core/YarrAssetManager.h"

void AYarrHUD::ShowDebugInfo(float& YL, float& YPos)
{
	Super::ShowDebugInfo(YL, YPos);
	
#if ENABLE_DRAW_DEBUG
	if (ShouldDisplayDebug("yarr"))
	{
		UYarrAssetManager::Get().DisplayDebug(DebugCanvas);
	}
#endif
}
