// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PreludiumPlayerController.h"
#include "EnhancedInputComponent.h"

APreludiumPlayerController::APreludiumPlayerController()
{
	
}

void APreludiumPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void APreludiumPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	AimTrace();
}

void APreludiumPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APreludiumPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APreludiumPlayerController::Look);

	
}

void APreludiumPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void APreludiumPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void APreludiumPlayerController::AimTrace()
{
	
}
