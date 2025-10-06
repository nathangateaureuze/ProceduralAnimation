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

	UPROPERTY(EditAnywhere, Category = "Insect", BlueprintReadOnly)
	TObjectPtr<UControlRigComponent> ControlRig;

	UPROPERTY(EditAnywhere, Category = "Insect")
	bool bOrientToFloor = true;


	/*	-------------------
	*	STATIC MESH MEMBERS
	*	-------------------	*/

	TObjectPtr <USceneComponent> MeshMembers;
	
	TObjectPtr <UStaticMeshComponent> SM_Abdomen;
	
	TObjectPtr <UStaticMeshComponent> SM_Thorax;
	
	TObjectPtr <UStaticMeshComponent> SM_Head;
	
	TObjectPtr <UStaticMeshComponent> SM_Antennae_L;	
	TObjectPtr <UStaticMeshComponent> SM_Antennae_R;
	
	TObjectPtr <UStaticMeshComponent> SM_Front_Femur_L;	
	TObjectPtr <UStaticMeshComponent> SM_Front_Tibia_L;	
	TObjectPtr <UStaticMeshComponent> SM_Front_Tarsus_L;
	TObjectPtr <UStaticMeshComponent> SM_Front_Femur_R;	
	TObjectPtr <UStaticMeshComponent> SM_Front_Tibia_R;	
	TObjectPtr <UStaticMeshComponent> SM_Front_Tarsus_R;
	
	TObjectPtr <UStaticMeshComponent> SM_Mid_Femur_L;
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tibia_L;	
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tarsus_L;	
	TObjectPtr <UStaticMeshComponent> SM_Mid_Femur_R;	
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tibia_R;	
	TObjectPtr <UStaticMeshComponent> SM_Mid_Tarsus_R;
	
	TObjectPtr <UStaticMeshComponent> SM_Back_Femur_L;	
	TObjectPtr <UStaticMeshComponent> SM_Back_Tibia_L;	
	TObjectPtr <UStaticMeshComponent> SM_Back_Tarsus_L;	
	TObjectPtr <UStaticMeshComponent> SM_Back_Femur_R;	
	TObjectPtr <UStaticMeshComponent> SM_Back_Tibia_R;
	TObjectPtr <UStaticMeshComponent> SM_Back_Tarsus_R;
	// END of STATIC MESH MEMBERS

public:

	/*	------
	*	ASSETS
	*	------	*/

	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Color", BlueprintReadWrite)
	TObjectPtr<UInsectColorAsset> Color1;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Color", BlueprintReadWrite)
	TObjectPtr<UInsectColorAsset> Color2;


	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member", BlueprintReadWrite)
	TObjectPtr<UInsectAbdomenAsset> Abdomen;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member", BlueprintReadWrite)
	TObjectPtr<UInsectAntennaeAsset> Antennae;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member", BlueprintReadWrite)
	TObjectPtr<UInsectHeadAsset> Head;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member", BlueprintReadWrite)
	TObjectPtr<UInsectLegAsset> Leg;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member", BlueprintReadWrite)
	TObjectPtr<UInsectThoraxAsset> Thorax;
	// END of ASSETS
private:

	UFUNCTION()
	const void SetHeight();

	UFUNCTION(BlueprintCallable)
	const void InitAllStaticMesh();

	UFUNCTION(BlueprintCallable)
	const void InitColor();

	UFUNCTION(BlueprintCallable)
	void OffsetMembers(UControlRigComponent* CRComponent);

	UFUNCTION()
	const void MapAllMemberComponent();


	UFUNCTION()
	void OrientToFloor(UControlRigComponent* CRComponent);


	void PostRegisterAllComponents() override;
 };