// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PirateCharacter.generated.h"

UCLASS()
class YARR_API APirateCharacter : public ACharacter
{
	GENERATED_BODY()
	// TODO: Attach These in the CPP
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "Pirate")
	TArray<TObjectPtr<USkeletalMesh>> BodyPartsToAttach;
};
