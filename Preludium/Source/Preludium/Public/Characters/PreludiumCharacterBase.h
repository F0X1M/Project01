// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PreludiumCharacterBase.generated.h"

UCLASS()
class PRELUDIUM_API APreludiumCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	APreludiumCharacterBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
};
