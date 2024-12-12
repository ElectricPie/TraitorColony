// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TPPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATPPlayerCharacter::ATPPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	CameraArmComponent->SetupAttachment(RootComponent);
	CameraArmComponent->TargetArmLength = 500.f;
	CameraArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CameraArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void ATPPlayerCharacter::MoveInDirection(const FVector2D MoveDirection)
{
	const FRotator Rotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MoveDirection.Y);
	AddMovementInput(RightDirection, MoveDirection.X);
}
