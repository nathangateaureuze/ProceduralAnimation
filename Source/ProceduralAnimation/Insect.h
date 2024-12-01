// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Insect.generated.h"

UCLASS()
class PROCEDURALANIMATION_API AInsect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInsect();

	USkeletalMeshComponent Body;

	UMeshComponent Head;
	UMeshComponent Abdomen;

	FTransform TestTransform;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
