// Fill out your copyright notice in the Description page of Project Settings.

#include "InsectCharacter.h"
#include "Components/CapsuleComponent.h"


AInsectCharacter::AInsectCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCapsuleSize(34, 34, false);

	ControlRig = CreateDefaultSubobject<UControlRigComponent>(TEXT("Insect_ControlRig"));
	ControlRig->SetupAttachment(GetCapsuleComponent());

	/*	-------------------
	*	STATIC MESH MEMBERS
	*	-------------------	*/

	MeshMembers = CreateDefaultSubobject<USceneComponent>(TEXT("Insect_Mesh_Members"));
	MeshMembers->SetupAttachment(GetCapsuleComponent());

	SM_Abdomen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Insect_Mesh_Abdomen"));
	SM_Abdomen->SetupAttachment(MeshMembers);
	SM_Thorax = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Insect_Mesh_Thorax"));
	SM_Thorax->SetupAttachment(MeshMembers);
	SM_Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Head"));
	SM_Head->SetupAttachment(MeshMembers);

	SM_Antennae_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Antennae_L"));
	SM_Antennae_L->SetupAttachment(MeshMembers);
	SM_Antennae_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Antennae_R"));
	SM_Antennae_R->SetupAttachment(MeshMembers);

	SM_Front_Femur_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Femur_L"));
	SM_Front_Femur_L->SetupAttachment(MeshMembers);
	SM_Front_Tibia_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tibia_L"));
	SM_Front_Tibia_L->SetupAttachment(MeshMembers);
	SM_Front_Tarsus_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tarsus_L"));
	SM_Front_Tarsus_L->SetupAttachment(MeshMembers);
	SM_Front_Femur_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Femur_R"));
	SM_Front_Femur_R->SetupAttachment(MeshMembers);
	SM_Front_Tibia_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tibia_R"));
	SM_Front_Tibia_R->SetupAttachment(MeshMembers);
	SM_Front_Tarsus_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Front_Tarsus_R"));
	SM_Front_Tarsus_R->SetupAttachment(MeshMembers);

	SM_Mid_Femur_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Femur_L"));
	SM_Mid_Femur_L->SetupAttachment(MeshMembers);
	SM_Mid_Tibia_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tibia_L"));
	SM_Mid_Tibia_L->SetupAttachment(MeshMembers);
	SM_Mid_Tarsus_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tarsus_L"));
	SM_Mid_Tarsus_L->SetupAttachment(MeshMembers);
	SM_Mid_Femur_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Femur_R"));
	SM_Mid_Femur_R->SetupAttachment(MeshMembers);
	SM_Mid_Tibia_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tibia_R"));
	SM_Mid_Tibia_R->SetupAttachment(MeshMembers);
	SM_Mid_Tarsus_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Mid_Tarsus_R"));
	SM_Mid_Tarsus_R->SetupAttachment(MeshMembers);

	SM_Back_Femur_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Femur_L"));
	SM_Back_Femur_L->SetupAttachment(MeshMembers);
	SM_Back_Tibia_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tibia_L"));
	SM_Back_Tibia_L->SetupAttachment(MeshMembers);
	SM_Back_Tarsus_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tarsus_L"));
	SM_Back_Tarsus_L->SetupAttachment(MeshMembers);
	SM_Back_Femur_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Femur_R"));
	SM_Back_Femur_R->SetupAttachment(MeshMembers);
	SM_Back_Tibia_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tibia_R"));
	SM_Back_Tibia_R->SetupAttachment(MeshMembers);
	SM_Back_Tarsus_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InsectMesh_Back_Tarsus_R"));
	SM_Back_Tarsus_R->SetupAttachment(MeshMembers);
	// END of STATIC MESH MEMBERS

}

const void AInsectCharacter::InitAllStaticMesh()
{
	UE_LOG(LogTemp, Warning, TEXT("InitMesh"));

	SM_Abdomen->SetStaticMesh(Abdomen->Mesh);
	SM_Thorax->SetStaticMesh(Thorax->Mesh);
	SM_Head->SetStaticMesh(Head->Mesh);

	SM_Antennae_L->SetStaticMesh(Antennae->Mesh);
	SM_Antennae_R->SetStaticMesh(Antennae->Mesh);

	SM_Front_Femur_L->SetStaticMesh(Leg->Mesh);
	SM_Front_Tibia_L->SetStaticMesh(Leg->MeshTibia);
	SM_Front_Tarsus_L->SetStaticMesh(Leg->MeshTarsus);
	SM_Front_Femur_R->SetStaticMesh(Leg->Mesh);
	SM_Front_Tibia_R->SetStaticMesh(Leg->MeshTibia);
	SM_Front_Tarsus_R->SetStaticMesh(Leg->MeshTarsus);

	SM_Mid_Femur_L->SetStaticMesh(Leg->Mesh);
	SM_Mid_Tibia_L->SetStaticMesh(Leg->MeshTibia);
	SM_Mid_Tarsus_L->SetStaticMesh(Leg->MeshTarsus);
	SM_Mid_Femur_R->SetStaticMesh(Leg->Mesh);
	SM_Mid_Tibia_R->SetStaticMesh(Leg->MeshTibia);
	SM_Mid_Tarsus_R->SetStaticMesh(Leg->MeshTarsus);

	SM_Back_Femur_L->SetStaticMesh(Leg->Mesh);
	SM_Back_Tibia_L->SetStaticMesh(Leg->MeshTibia);
	SM_Back_Tarsus_L->SetStaticMesh(Leg->MeshTarsus);
	SM_Back_Femur_R->SetStaticMesh(Leg->Mesh);
	SM_Back_Tibia_R->SetStaticMesh(Leg->MeshTibia);
	SM_Back_Tarsus_R->SetStaticMesh(Leg->MeshTarsus);

	return;
}

static const FTransform MirrorTransform(FTransform Transform) {
	FVector Location = Transform.GetLocation();
	Location.X = Location.X * (-1);

	Transform.SetLocation(Location);

	FVector Scale = Transform.GetScale3D();
	Scale.X = Scale.X * (-1);

	Transform.SetScale3D(Scale);

	FVector Rotation = Transform.GetRotation().Euler();
	Rotation.Z = Rotation.Z * (-1);

	Transform.SetRotation(FQuat::MakeFromEuler(Rotation));

	return Transform;
}

void AInsectCharacter::OffsetMembers(UControlRigComponent* CRComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("OffsetMembers"));

	CRComponent->SetInitialBoneTransform(FName("Abdomen"), Abdomen->Transform, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Thorax"), Abdomen->ThoraxSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Head"), Thorax->HeadSocket, EControlRigComponentSpace::LocalSpace, false);

	CRComponent->SetInitialBoneTransform(FName("Antennae_R_001"), Head->AntennaeSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Antennae_L_001"), MirrorTransform(Head->AntennaeSocket), EControlRigComponentSpace::LocalSpace, false);

	CRComponent->SetInitialBoneTransform(FName("Hip_Front_R"), Thorax->FrontLegSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Leg_Front_R"), Leg->TibiaSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Foot_Front_R"), Leg->TarsusSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Hip_Front_L"), MirrorTransform(Thorax->FrontLegSocket), EControlRigComponentSpace::LocalSpace, true);
	CRComponent->SetInitialBoneTransform(FName("Leg_Front_L"), Leg->TibiaSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Foot_Front_L"), Leg->TarsusSocket, EControlRigComponentSpace::LocalSpace, false);

	CRComponent->SetInitialBoneTransform(FName("Hip_Mid_R"), Abdomen->MidLegSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Leg_Mid_R"), Leg->TibiaSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Foot_Mid_R"), Leg->TarsusSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Hip_Mid_L"), MirrorTransform(Abdomen->MidLegSocket), EControlRigComponentSpace::LocalSpace, true);
	CRComponent->SetInitialBoneTransform(FName("Leg_Mid_L"), Leg->TibiaSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Foot_Mid_L"), Leg->TarsusSocket, EControlRigComponentSpace::LocalSpace, false);

	CRComponent->SetInitialBoneTransform(FName("Hip_Bak_R"), Abdomen->BackLegSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Leg_Back_R"), Leg->TibiaSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Foot_Back_R"), Leg->TarsusSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Hip_Bak_L"), MirrorTransform(Abdomen->BackLegSocket), EControlRigComponentSpace::LocalSpace, true);
	CRComponent->SetInitialBoneTransform(FName("Leg_Back_L"), Leg->TibiaSocket, EControlRigComponentSpace::LocalSpace, false);
	CRComponent->SetInitialBoneTransform(FName("Foot_Back_L"), Leg->TarsusSocket, EControlRigComponentSpace::LocalSpace, false);

	return;
}

const void AInsectCharacter::MapAllMemberComponent()
{
	TArray<FControlRigComponentMappedComponent> MappedComponents = {};
	

	FControlRigComponentMappedComponent MappedComponentInfo = FControlRigComponentMappedComponent();

	MappedComponentInfo.Component = SM_Abdomen;
	MappedComponentInfo.ElementName = TEXT("Abdomen");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Thorax;
	MappedComponentInfo.ElementName = TEXT("Thorax");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Head;
	MappedComponentInfo.ElementName = TEXT("Head");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Antennae_R;
	MappedComponentInfo.ElementName = TEXT("Antennae_R_001");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Antennae_L;
	MappedComponentInfo.ElementName = TEXT("Antennae_L_001");
	MappedComponents.Add(MappedComponentInfo);

	// Front Legs
	MappedComponentInfo.Component = SM_Front_Femur_L;
	MappedComponentInfo.ElementName = TEXT("Hip_Front_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Front_Tibia_L;
	MappedComponentInfo.ElementName = TEXT("Leg_Front_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Front_Tarsus_L;
	MappedComponentInfo.ElementName = TEXT("Foot_Front_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Front_Femur_R;
	MappedComponentInfo.ElementName = TEXT("Hip_Front_R");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Front_Tibia_R;
	MappedComponentInfo.ElementName = TEXT("Leg_Front_R");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Front_Tarsus_R;
	MappedComponentInfo.ElementName = TEXT("Foot_Front_R");
	MappedComponents.Add(MappedComponentInfo);

	// Mid Legs
	MappedComponentInfo.Component = SM_Mid_Femur_L;
	MappedComponentInfo.ElementName = TEXT("Hip_Mid_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Mid_Tibia_L;
	MappedComponentInfo.ElementName = TEXT("Leg_Mid_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Mid_Tarsus_L;
	MappedComponentInfo.ElementName = TEXT("Foot_Mid_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Mid_Femur_R;
	MappedComponentInfo.ElementName = TEXT("Hip_Mid_R");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Mid_Tibia_R;
	MappedComponentInfo.ElementName = TEXT("Leg_Mid_R");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Mid_Tarsus_R;
	MappedComponentInfo.ElementName = TEXT("Foot_Mid_R");
	MappedComponents.Add(MappedComponentInfo);

	// Back Legs
	MappedComponentInfo.Component = SM_Back_Femur_L;
	MappedComponentInfo.ElementName = TEXT("Hip_Bak_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Back_Tibia_L;
	MappedComponentInfo.ElementName = TEXT("Leg_Back_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Back_Tarsus_L;
	MappedComponentInfo.ElementName = TEXT("Foot_Back_L");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Back_Femur_R;
	MappedComponentInfo.ElementName = TEXT("Hip_Bak_R");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Back_Tibia_R;
	MappedComponentInfo.ElementName = TEXT("Leg_Back_R");
	MappedComponents.Add(MappedComponentInfo);

	MappedComponentInfo.Component = SM_Back_Tarsus_R;
	MappedComponentInfo.ElementName = TEXT("Foot_Back_R");
	MappedComponents.Add(MappedComponentInfo);

	ControlRig->AddMappedComponents(MappedComponents);

	return;
}

void AInsectCharacter::PostRegisterAllComponents()
{
	Super::PostRegisterAllComponents();

	if (Abdomen && Thorax && Head && Antennae && Leg)
	{
		InitAllStaticMesh();

		ControlRig->OnPreConstructionDelegate.AddUniqueDynamic(this, &AInsectCharacter::OffsetMembers);

		MapAllMemberComponent();
	}
	else
	{
		ControlRig->OnPreConstructionDelegate.Clear();

		UE_LOG(LogTemp, Error, TEXT("Invalid Assets"));
	}

	return;
}