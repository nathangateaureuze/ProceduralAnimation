// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "ControlRig.h"
#include "ControlRigComponent.h"

#include "InsectAssets/InsectColorAsset.h"

#include "InsectAssets/Members/InsectAbdomenAsset.h"
#include "InsectAssets/Members/InsectAntennaeAsset.h"
#include "InsectAssets/Members/InsectHeadAsset.h"
#include "InsectAssets/Members/InsectLegAsset.h"
#include "InsectAssets/Members/InsectThoraxAsset.h"

#include "InsectCharacter.generated.h"

UCLASS()
class PROCEDURALANIMATION_API AInsectCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AInsectCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, Category = "Insect")
	TObjectPtr<UControlRigComponent> ControlRig;

	/*	------
	*	ASSETS
	*	------	*/
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Color")
	TObjectPtr<UInsectColorAsset> Color1;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Color")
	TObjectPtr<UInsectColorAsset> Color2;

	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	TObjectPtr<UInsectAbdomenAsset> Abdomen;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	TObjectPtr<UInsectAntennaeAsset> Antennae;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	TObjectPtr<UInsectHeadAsset> Head;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	TObjectPtr<UInsectLegAsset> Leg;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	TObjectPtr<UInsectThoraxAsset> Thorax;
	// END of ASSETS


	/*	-------------------
	*	STATIC MESH MEMBERS
	*	-------------------	*/
	UPROPERTY(EditAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Abdomen;

	UPROPERTY(EditAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Thorax;
	// END of STATIC MESH MEMBERS


	UFUNCTION()
	void InitMesh();

	UFUNCTION()
	void OffsetMembers(UControlRigComponent* CRComponent);


	void PostRegisterAllComponents() override;

	void OnConstruction(const FTransform& Transform) override;
 };
