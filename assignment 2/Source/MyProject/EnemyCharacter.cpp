// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//fetch character currently being controlled
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	//set enemy rotation
	LookAtActor(PlayerCharacter);

}

void AEnemyCharacter::LookAtActor(AActor* TargetActor)
{
	if (TargetActor == nullptr) return;

	if (CanSeeActor(TargetActor)) {
		//setting location of enemy and target
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();

		//caculate rotation for start point to face end point
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);


		SetActorRotation(LookAtRotation);
	}


}

bool AEnemyCharacter::CanSeeActor(const AActor* const TargetActor) const
{
	if (TargetActor == nullptr) return false;

	FHitResult Hit;

	FVector Start = GetActorLocation();
	FVector End = TargetActor->GetActorLocation();

	ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;

	
	FCollisionQueryParams  QueryParams;

	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(TargetActor);


	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	FColor LineColor = (Hit.bBlockingHit) ? FColor::Green : FColor::Red;

	DrawDebugLine(GetWorld(), Start, End, LineColor);

	return !Hit.bBlockingHit;
}

//// Called to bind functionality to input
//void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

