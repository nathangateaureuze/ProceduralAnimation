// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "InsectCharacter.h"

#define ATTACHMENTRULES FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, EAttachmentRule::KeepRelative, false)
#define DETACHMENTRULES FDetachmentTransformRules(EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, false)

AInsectCharacter::AInsectCharacter():
	ControlRig(nullptr),
	Color1(nullptr),
	Color2(nullptr),
	Abdomen(nullptr),
	Antennae(nullptr),
	Head(nullptr),
	Leg(nullptr),
	Thorax(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;

	ControlRig = CreateDefaultSubobject<UControlRigComponent>(TEXT("InsectCharacterControlRig"));
	ControlRig->SetupAttachment(GetCapsuleComponent());

	ControlRig->bDrawBones = true;
	ControlRig->bShowDebugDrawing = true;

	
	/*	-------------------
	*	STATIC MESH MEMBERS
	*	-------------------	*/

	SM_Abdomen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Abdomen"));
	SM_Thorax = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Thorax"));
	SM_Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Head"));

	SM_Antennae_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Antennae_L"));
	SM_Antennae_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Antennae_R"));

	SM_Front_Femur_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Femur_L"));
	SM_Front_Tibia_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tibia_L"));
	SM_Front_Tarsus_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tarsus_L"));
	SM_Front_Femur_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Femur_R"));
	SM_Front_Tibia_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tibia_R"));
	SM_Front_Tarsus_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tarsus_R"));

	SM_Mid_Femur_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Femur_L"));
	SM_Mid_Tibia_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tibia_L"));
	SM_Mid_Tarsus_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tarsus_L"));
	SM_Mid_Femur_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Femur_R"));
	SM_Mid_Tibia_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tibia_R"));
	SM_Mid_Tarsus_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tarsus_R"));

	SM_Back_Femur_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Femur_L"));
	SM_Back_Tibia_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tibia_L"));
	SM_Back_Tarsus_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tarsus_L"));
	SM_Back_Femur_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Femur_R"));
	SM_Back_Tibia_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tibia_R"));
	SM_Back_Tarsus_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tarsus_R"));

	// END of STATIC MESH MEMBERS

	//ControlRig->OnPreConstructionDelegate.AddUniqueDynamic(this, &AInsectCharacter::OffsetMembers);

}


void AInsectCharacter::InitMesh()
{
	if (!(Abdomen && Antennae && Thorax && Leg && Head))
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to retreive members assets"));
		return;
	}

	SM_Abdomen->SetStaticMesh(Abdomen->Mesh);
	SM_Thorax->SetStaticMesh(Thorax->Mesh);
	SM_Head->SetStaticMesh(Head->Mesh);

	SM_Antennae_L->SetStaticMesh(Antennae->Mesh);
	SM_Antennae_R->SetStaticMesh(Antennae->Mesh);

	// TODO LEGS
}


void AInsectCharacter::InitMembers(UControlRigComponent* CRComponent)
{
	CRComponent->AddMappedSkeletalMesh(
		GetMesh(),
		TArray<FControlRigComponentMappedBone>{},
		TArray<FControlRigComponentMappedCurve>{},
		EControlRigComponentMapDirection::Input
	);
}


void AInsectCharacter::OffsetMembers(UControlRigComponent* CRComponent)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, FString("Offset"));
	CRComponent->SetBoneTransform(FName("Abdomen"), FTransform(FRotator(),FVector(0,0,0), FVector(1, 1, 1)), EControlRigComponentSpace::LocalSpace, true);
	//CRComponent->SetBoneTransform(FName("Thorax"), Abdomen->ThoraxSocket, EControlRigComponentSpace::LocalSpace, true);
}

void AInsectCharacter::ResetMembers()
{
	SM_Abdomen->DetachFromComponent(DETACHMENTRULES);
	SM_Thorax->DetachFromComponent(DETACHMENTRULES);

	const FTransform BaseTransform = FTransform();

	SM_Abdomen->SetRelativeTransform(BaseTransform);
	SM_Thorax->SetRelativeTransform(BaseTransform);
}


void AInsectCharacter::AttachMembers(UControlRigComponent* CRComponent)
{
	//ResetMembers();

	SM_Abdomen->AttachToComponent(GetMesh(), ATTACHMENTRULES, "Abdomen");
	SM_Thorax->AttachToComponent(GetMesh(), ATTACHMENTRULES, "Thorax");

}

void AInsectCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitMesh();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString("BeginPlay"));
	
}

void AInsectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInsectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AInsectCharacter::OnConstruction(const FTransform& Transform)
{
	//InitMesh();
	//ControlRig->OnPreInitializeDelegate.AddUniqueDynamic(this, &AInsectCharacter::InitMembers);
	//ControlRig->OnPostConstructionDelegate.AddUniqueDynamic(this, &AInsectCharacter::AttachMembers);
}

