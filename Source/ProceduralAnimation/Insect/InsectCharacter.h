// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

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


	/*	-------------------
	*	STATIC MESH MEMBERS
	*	-------------------	*/

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Abdomen;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Thorax;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Head;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Antennae_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Antennae_R;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Front_Femur_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Front_Tibia_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Front_Tarsus_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Front_Femur_R;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Front_Tibia_R;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Front_Tarsus_R;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Mid_Femur_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tibia_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tarsus_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Mid_Femur_R;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tibia_R;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tarsus_R;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Back_Femur_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Back_Tibia_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Back_Tarsus_L;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Back_Femur_R;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Back_Tibia_R;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr <UStaticMeshComponent> SM_Back_Tarsus_R;
	// END of STATIC MESH MEMBERS

private:

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


	UFUNCTION()
	const void InitAllStaticMesh();

	UFUNCTION()
	void OffsetMembers(UControlRigComponent* CRComponent);

	UFUNCTION()
	const void MapAllMemberComponent();


	void PostRegisterAllComponents() override;
 };