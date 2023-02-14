// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFPSCharacter.h"

// Sets default values
AMyFPSCharacter::AMyFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	//setup input bindings
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyFPSCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("Lookup"), this, &AMyFPSCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed ,this, &AMyFPSCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AMyFPSCharacter::StopJumping);

}

void AMyFPSCharacter::MoveForward(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void AMyFPSCharacter::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}

