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

	AInsectCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect")
	TObjectPtr <UControlRigComponent> ControlRig;

private:


	/*	------
	*	ASSETS
	*	------	*/

	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Color")
	UInsectColorAsset* Color1;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Color")
	UInsectColorAsset* Color2;

	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	UInsectAbdomenAsset* Abdomen;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	UInsectAntennaeAsset* Antennae;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Asset|Member")
	UInsectHeadAsset* Head;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	UInsectLegAsset* Leg;
	UPROPERTY(EditAnywhere, Category = "Insect|Asset|Member")
	UInsectThoraxAsset* Thorax;

	// END of ASSETS


	/*	-------------------
	*	STATIC MESH MEMBERS
	*	-------------------	*/

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	TObjectPtr <UStaticMeshComponent> SM_Abdomen;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Thorax;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Head;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Antennae_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Antennae_R;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Front_Femur_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Front_Tibia_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Front_Tarsus_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Front_Femur_R;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Front_Tibia_R;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Front_Tarsus_R;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Mid_Femur_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Mid_Tibia_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Mid_Tarsus_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Mid_Femur_R;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Mid_Tibia_R;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Mid_Tarsus_R;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Back_Femur_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Back_Tibia_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Back_Tarsus_L;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Back_Femur_R;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Back_Tibia_R;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Insect", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_Back_Tarsus_R;


	TArray<UStaticMeshComponent*> MeshMembers = {
		SM_Abdomen , SM_Thorax, SM_Head, SM_Antennae_L, SM_Antennae_R,
		SM_Front_Femur_L, SM_Front_Femur_R, SM_Front_Tarsus_L, SM_Front_Tarsus_R, SM_Front_Tibia_L, SM_Front_Tibia_R,
		SM_Mid_Femur_L, SM_Mid_Femur_R, SM_Mid_Tarsus_L, SM_Mid_Tarsus_R, SM_Mid_Tibia_L, SM_Mid_Tibia_R,
		SM_Back_Femur_L, SM_Back_Femur_R, SM_Back_Tarsus_L, SM_Back_Tarsus_R, SM_Back_Tibia_L, SM_Back_Tibia_R,
	};

	TArray<UStaticMeshComponent*> MeshFemurs = {
		SM_Front_Femur_L, SM_Front_Femur_R,
		SM_Mid_Femur_L, SM_Mid_Femur_R,
		SM_Back_Femur_L, SM_Back_Femur_R,
	};

	TArray<UStaticMeshComponent*> MeshTibias = {
		SM_Front_Tibia_L, SM_Front_Tibia_R,
		SM_Mid_Tibia_L, SM_Mid_Tibia_R,
		SM_Back_Tibia_L, SM_Back_Tibia_R,
	};

	TArray<UStaticMeshComponent*> MeshTarsus = {
		SM_Front_Tarsus_L, SM_Front_Tarsus_R,
		SM_Mid_Tarsus_L, SM_Mid_Tarsus_R,
		SM_Back_Tarsus_L, SM_Back_Tarsus_R,
	};

	// END of STATIC MESH MEMBERS

	UFUNCTION()
	void InitMesh();

	UFUNCTION()
	void InitMembers(UControlRigComponent* CRComponent);

	UFUNCTION()
	void OffsetMembers(UControlRigComponent* CRComponent);

	void ResetMembers();

	UFUNCTION()
	void AttachMembers(UControlRigComponent* CRComponent);


protected:

	virtual void BeginPlay() override;


public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnConstruction(const FTransform& Transform) override;
};
