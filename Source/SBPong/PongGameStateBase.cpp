// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameStateBase.h"
#include "PlayerHUD.h"

int APongGameStateBase::GetPlayerScore()
{
    return PlayerScore;
}

int APongGameStateBase::GetCpuScore()
{
    return CpuScore;
}

void APongGameStateBase::IncrementPlayerScore()
{
    PlayerScore++;
}

void APongGameStateBase::IncrementCpuScore()
{
    CpuScore++;
}

void APongGameStateBase::BeginPlay()
{
	Super::BeginPlay();

	if (WBP_PlayerHUD)
	{
		PlayerHudInstance = CreateWidget<UPlayerHUD>(GetWorld(), WBP_PlayerHUD);

		PlayerHudInstance->AddToViewport();
	}
}
