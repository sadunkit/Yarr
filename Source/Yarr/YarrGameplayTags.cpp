// Copyright 2023 sadunkit
// @see https://github.com/sadunkit/yarr

#include "YarrGameplayTags.h"

#include "YarrLogChannels.h"

namespace YarrGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Pirate, "Pirate", "A pirate");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Pirate_BodyPart_Base, "Pirate.BodyPart.Base", "A pirate body part");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Pirate_BodyPart_Accessory, "Pirate.BodyPart.Accessory", "A pirate accessory part");

	FGameplayTag FindTagByString(const FString& TagString, bool bMatchPartialString)
	{
		const UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
		FGameplayTag Tag = Manager.RequestGameplayTag(FName(*TagString), false);

		if (!Tag.IsValid() && bMatchPartialString)
		{
			FGameplayTagContainer AllTags;
			Manager.RequestAllGameplayTags(AllTags, true);

			for (const FGameplayTag& TestTag : AllTags)
			{
				if (TestTag.ToString().Contains(TagString))
				{
					UE_LOG(LogYarr, Display, TEXT("Could not find exact match for tag [%s] but found partial match on tag [%s]."), *TagString, *TestTag.ToString());
					Tag = TestTag;
					break;
				}
			}
		}

		return Tag;
	}
}
