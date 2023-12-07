// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PirateCharacter.generated.h"

UCLASS()
class YARR_API APirateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APirateCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(BlueprintReadOnly, Category = "Pirate")
	TArray<const USkeletalMesh*> BodyPartsToAttach;
	
	// TODO: Attach These in the CPP
};
