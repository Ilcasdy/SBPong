// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"
#include "GameFramework/FloatingPawnMovement.h"

// handles vertical movement set to w and s keys
void APlayerPaddle::MoveUp(float Amount)
{
    FloatingPawnMovement->AddInputVector(GetActorUpVector() * Amount);
}

void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPaddle::MoveUp);
}
