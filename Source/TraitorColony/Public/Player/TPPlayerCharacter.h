// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TRAITORCOLONY_API ATPPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPPlayerCharacter();

	void MoveInDirection(const FVector2D MoveDirection);

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraArmComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;
	
};
