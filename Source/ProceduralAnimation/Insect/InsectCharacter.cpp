// Fill out your copyright notice in the Description page of Project Settings.

#include "InsectCharacter.h"
#include "Components/CapsuleComponent.h"

#define ATTACHMENTRULES FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, false)
#define DETACHMENTRULES FDetachmentTransformRules(EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, false)

AInsectCharacter::AInsectCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCapsuleSize(34, 34, false);

	ControlRig = CreateDefaultSubobject<UControlRigComponent>(TEXT("Insect_ControlRig"));
	if (ControlRig)
	{
		ControlRig->SetupAttachment(GetCapsuleComponent());
	}

	SM_Abdomen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Insect_Mesh_Abdomen"));
	if (SM_Abdomen)
	{
		SM_Abdomen->SetupAttachment(GetCapsuleComponent());
	}

	SM_Thorax = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Insect_Mesh_Thorax"));
	if (SM_Thorax)
	{
		SM_Thorax->SetupAttachment(GetCapsuleComponent());
	}

}

void AInsectCharacter::InitMesh()
{
	UE_LOG(LogTemp, Warning, TEXT("InitMesh"));

	if (Abdomen && Thorax && Head && Antennae && Leg &&
		SM_Abdomen && SM_Thorax)
	{
		SM_Abdomen->SetStaticMesh(Abdomen->Mesh);
		SM_Thorax->SetStaticMesh(Thorax->Mesh);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InitMesh"));
	}
}


void AInsectCharacter::OffsetMembers(UControlRigComponent* CRComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("OffsetMembers"));

	if (CRComponent && Thorax && Head && Antennae && Leg &&
		ControlRig && SM_Abdomen && SM_Thorax)
	{
		CRComponent->SetInitialBoneTransform(FName("Abdomen"), Abdomen->Transform, EControlRigComponentSpace::LocalSpace, true);

		CRComponent->SetInitialBoneTransform(FName("Thorax"), Abdomen->ThoraxSocket, EControlRigComponentSpace::LocalSpace, true);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("OffsetMembers"));
	}

}

void AInsectCharacter::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	InitMesh();

	ControlRig->OnPreConstructionDelegate.AddUniqueDynamic(this, &AInsectCharacter::OffsetMembers);
}

void AInsectCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	FControlRigComponentMappedComponent MappedAbdomenInfo = FControlRigComponentMappedComponent();
	MappedAbdomenInfo.Component = SM_Abdomen;
	MappedAbdomenInfo.ElementName = TEXT("Abdomen");

	FControlRigComponentMappedComponent MappedThoraxInfo = FControlRigComponentMappedComponent();
	MappedThoraxInfo.Component = SM_Thorax;
	MappedThoraxInfo.ElementName = TEXT("Thorax");

	ControlRig->AddMappedComponents(TArray<FControlRigComponentMappedComponent>{MappedAbdomenInfo, MappedThoraxInfo});
}

