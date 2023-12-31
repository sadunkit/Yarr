﻿// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

#pragma once

#include "NativeGameplayTags.h"

namespace YarrGameplayTags
{
	YARR_API	FGameplayTag FindTagByString(const FString& TagString, bool bMatchPartialString = false);
	
	YARR_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Pirate);
	YARR_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Pirate_BodyPart_Base);
	YARR_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Pirate_BodyPart_Accessory);
}