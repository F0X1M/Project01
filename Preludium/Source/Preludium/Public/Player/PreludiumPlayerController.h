// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PreludiumPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class PRELUDIUM_API APreludiumPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APreludiumPlayerController();

	virtual void BeginPlay() override;
	
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UFUNCTION(BlueprintCallable)
	void Move(const FInputActionValue& InputActionValue);

	UFUNCTION(BlueprintCallable)
	void Look(const FInputActionValue& InputActionValue);

	void AimTrace();
	
};
