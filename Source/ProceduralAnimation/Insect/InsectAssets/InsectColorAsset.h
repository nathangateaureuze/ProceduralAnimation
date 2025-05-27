// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../InsectAsset.h"
#include "InsectColorAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALANIMATION_API UInsectColorAsset : public UInsectAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FLinearColor Color;
};
