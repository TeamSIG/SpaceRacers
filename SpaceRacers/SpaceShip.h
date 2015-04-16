// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "SpaceShip.generated.h"

UCLASS()
class SPACERACERS_API ASpaceShip : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY()
		bool grounded;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GravitySystem")
		float groundDistance;

	// Sets default values for this character's properties
	ASpaceShip();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

};
