// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../InsectMemberAsset.h"
#include "InsectThoraxAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALANIMATION_API UInsectThoraxAsset : public UInsectMemberAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FTransform HeadSocket;

	UPROPERTY(EditAnywhere)
	FTransform FrontLegSocket;
};
