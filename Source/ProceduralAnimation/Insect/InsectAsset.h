// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InsectAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALANIMATION_API UInsectAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere)
	FName Name;
};
