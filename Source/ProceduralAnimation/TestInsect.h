// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "ControlRigComponent.h"

#include "TestInsect.generated.h"

UCLASS()
class PROCEDURALANIMATION_API ATestInsect : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestInsect();

	UFUNCTION()
	void OffsetMembers(UControlRigComponent* CRComponent);

	virtual void OnConstruction(const FTransform& Transform) override;


public:

	UPROPERTY(EditAnywhere)
	UControlRigComponent* ControlRig;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
