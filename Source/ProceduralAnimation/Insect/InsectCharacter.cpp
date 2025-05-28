// Fill out your copyright notice in the Description page of Project Settings.

#include "InsectCharacter.h"
#include "Components/CapsuleComponent.h"

#define ATTACHMENTRULES FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, false)
#define DETACHMENTRULES FDetachmentTransformRules(EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, false)

AInsectCharacter::AInsectCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	ControlRig = CreateDefaultSubobject<UControlRigComponent>(TEXT("Insect_ControlRig"));
	if (ControlRig)
	{
		ControlRig->SetupAttachment(GetMesh());
	}

	SM_Abdomen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Insect_Mesh_Abdomen"));
	if (SM_Abdomen)
	{
		SM_Abdomen->SetupAttachment(GetMesh());
	}

	SM_Thorax = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Insect_Mesh_Thorax"));
	if (SM_Thorax)
	{
		SM_Thorax->SetupAttachment(GetMesh());
	}

}

void AInsectCharacter::InitMesh()
{
	UE_LOG(LogTemp, Warning, TEXT("InitMesh"));

	SM_Abdomen->SetStaticMesh(Abdomen->Mesh);
	SM_Thorax->SetStaticMesh(Thorax->Mesh);
}


void AInsectCharacter::OffsetMembers(UControlRigComponent* CRComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("OffsetMembers"));

	CRComponent->SetInitialBoneTransform(FName("Abdomen"), Abdomen->Transform, EControlRigComponentSpace::LocalSpace, true);
	CRComponent->SetInitialBoneTransform(FName("Thorax"), Abdomen->ThoraxSocket, EControlRigComponentSpace::LocalSpace, true);
}

void AInsectCharacter::AttachMembers(UControlRigComponent* CRComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("AttachMembers"));

	SM_Abdomen->AttachToComponent(GetMesh(), ATTACHMENTRULES, "Abdomen");
	SM_Thorax->AttachToComponent(GetMesh(), ATTACHMENTRULES, "Thorax");
}

void AInsectCharacter::SkinMesh(UControlRigComponent* CRComponent)
{
	CRComponent->AddMappedCompleteSkeletalMesh(GetMesh());
}

void AInsectCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UE_LOG(LogTemp, Warning, TEXT("OnConstruction"));

	if (Abdomen && Thorax && Head && Antennae && Leg && 
		ControlRig && SM_Abdomen && SM_Thorax)
	{
		InitMesh();

		ControlRig->OnPreConstructionDelegate.AddUniqueDynamic(this, &AInsectCharacter::OffsetMembers);
		ControlRig->OnPreConstructionDelegate.AddUniqueDynamic(this, &AInsectCharacter::AttachMembers);
		ControlRig->OnPreInitializeDelegate.AddUniqueDynamic(this, &AInsectCharacter::SkinMesh);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to retreive members assets"));
	}
}

