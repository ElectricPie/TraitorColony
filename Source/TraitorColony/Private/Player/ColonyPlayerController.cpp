// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ColonyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/TPPlayerCharacter.h"

void AColonyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AColonyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AColonyPlayerController::Move);
		
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AColonyPlayerController::Look);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AColonyPlayerController::StartJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AColonyPlayerController::StopJump);
	}
}

void AColonyPlayerController::Move(const FInputActionValue& InputActionValue)
{
	if (ATPPlayerCharacter* PlayerCharacter = Cast<ATPPlayerCharacter>(GetPawn()))
	{
		const FVector2D MoveDirection = InputActionValue.Get<FVector2D>();
		PlayerCharacter->MoveInDirection(MoveDirection);
	}
}

void AColonyPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookDirection = InputActionValue.Get<FVector2D>();

	AddYawInput(LookDirection.X);
	AddPitchInput(LookDirection.Y);
}

void AColonyPlayerController::StartJump()
{
	if (ACharacter* PlayerCharacter = Cast<ACharacter>(GetPawn()))
	{
		PlayerCharacter->Jump();
	}
}

void AColonyPlayerController::StopJump()
{
	if (ACharacter* PlayerCharacter = Cast<ACharacter>(GetPawn()))
	{
		PlayerCharacter->StopJumping();
	}
}