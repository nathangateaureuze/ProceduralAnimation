// Fill out your copyright notice in the Description page of Project Settings.


#include "TestInsect.h"

// Sets default values
ATestInsect::ATestInsect()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ControlRig = CreateDefaultSubobject<UControlRigComponent>(TEXT("InsectCharacterControlRig"));

}

void ATestInsect::OffsetMembers(UControlRigComponent* CRComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("Le test offset"));
	CRComponent->SetInitialBoneTransform(FName("Abdomen"), FTransform(), EControlRigComponentSpace::LocalSpace, true);
}

void ATestInsect::OnConstruction(const FTransform& Transform)
{
	ControlRig->OnPreConstructionDelegate.AddUniqueDynamic(this, &ATestInsect::OffsetMembers);
}

// Called when the game starts or when spawned
void ATestInsect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestInsect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestInsect::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

