// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class SBPONG_API APongGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:

	int GetPlayerScore();

	int GetCpuScore();

private:

	int PlayerScore = 0;
	int CpuScore = 0;
	
};
