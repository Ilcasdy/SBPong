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

	void IncrementPlayerScore();

	void IncrementCpuScore();

	UPROPERTY(EditAnywhere, Category = HUD)
	TSubclassOf<class UPlayerHUD> WBP_PlayerHUD;

	class UPlayerHUD* PlayerHudInstance;

	virtual void BeginPlay() override;


private:

	int PlayerScore = 0;
	int CpuScore = 0;
	
};
