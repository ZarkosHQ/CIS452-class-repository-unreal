// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController1.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerController1 : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "OurVariables")
	float Health = 1.0f;


};
