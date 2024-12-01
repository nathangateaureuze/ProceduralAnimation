// Fill out your copyright notice in the Description page of Project Settings.


#include "Insect.h"

// Sets default values
AInsect::AInsect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInsect::BeginPlay()
{
    Super::BeginPlay();

    // Call to update the bone positions immediately
    Body.RefreshBoneTransforms();
}

// Called every frame
void AInsect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

