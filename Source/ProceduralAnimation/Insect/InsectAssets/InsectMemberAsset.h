// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../InsectAsset.h"
#include "InsectMemberAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALANIMATION_API UInsectMemberAsset : public UInsectAsset
{
	GENERATED_BODY()

public: 

	UPROPERTY(EditAnywhere)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere)
	UMaterialInstance* Material;
};
