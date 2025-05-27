// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../InsectMemberAsset.h"
#include "InsectLegAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALANIMATION_API UInsectLegAsset : public UInsectMemberAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	UStaticMesh* MeshTibia;

	UPROPERTY(EditAnywhere)
	UStaticMesh* MeshTarsus;


	UPROPERTY(EditAnywhere)
	FTransform TibiaSocket;

	UPROPERTY(EditAnywhere)
	FTransform TarsusSocket;
};
