// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PongPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SBPONG_API APongPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APongPlayerController();

protected:


	virtual void BeginPlay() override;
	
};
