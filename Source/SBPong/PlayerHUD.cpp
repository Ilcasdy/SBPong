// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Components/TextBlock.h"
#include "PongGameStateBase.h"

bool UPlayerHUD::Initialize()
{
    bool Success = Super::Initialize();

    if (PlayerScoreText)
    {
        PlayerScoreText->TextDelegate.BindUFunction(this, "SetPlayerScoreText");
    }
    if (CpuScoreText)
    {
        CpuScoreText->TextDelegate.BindUFunction(this, "SetCpuScoreText");
    }

    return true;
}

FText UPlayerHUD::SetPlayerScoreText()
{
    APongGameStateBase* GS = Cast<APongGameStateBase>(GetWorld()->GetGameState());
    if (GS)
    {
        return FText::FromString(FString::FromInt(GS->GetPlayerScore()));
    }
    return FText::FromString("NULL");
}

FText UPlayerHUD::SetCpuScoreText()
{
    APongGameStateBase* GS = Cast<APongGameStateBase>(GetWorld()->GetGameState());
    if (GS)
    {
        return FText::FromString(FString::FromInt(GS->GetCpuScore()));
    }
    return FText::FromString("NULL");
}

