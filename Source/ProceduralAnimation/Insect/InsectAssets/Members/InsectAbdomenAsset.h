// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../InsectMemberAsset.h"
#include "InsectAbdomenAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALANIMATION_API UInsectAbdomenAsset : public UInsectMemberAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	FTransform Transform;

	UPROPERTY(EditAnywhere)
	FTransform ThoraxSocket;

	UPROPERTY(EditAnywhere)
	FTransform FrontLegSocket;

	UPROPERTY(EditAnywhere)
	FTransform MidLegSocket;

	UPROPERTY(EditAnywhere)
	FTransform BackLegSocket;
};
