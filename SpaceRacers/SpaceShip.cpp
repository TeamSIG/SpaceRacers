// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceRacers.h"
#include "SpaceShip.h"


// Sets default values
ASpaceShip::ASpaceShip()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->groundDistance = 10.0f;
	this->grounded = false;

}

// Called when the game starts or when spawned
void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult hit;
	FVector direction = this->GetActorLocation() + this->GetActorUpVector() * -1 * this->groundDistance;
	DrawDebugLine(this->GetWorld(), this->GetActorLocation(), direction, FColor::Red, false, 2.0f);
	if (this->ActorLineTraceSingle(hit, this->GetActorLocation(), direction, ECollisionChannel::ECC_Visibility, FCollisionQueryParams())){
		//isgrounded
		this->grounded = true;
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Green, TEXT("Grounded"));
	}
	else{
		this->grounded = false;
		GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Green, TEXT("Flying"));
	}
}

// Called to bind functionality to input
void ASpaceShip::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

