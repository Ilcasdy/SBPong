// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"
#include "GameFramework/FloatingPawnMovement.h"

void APlayerPaddle::MoveUp(float Amount)
{
    FloatingPawnMovement->AddInputVector(GetActorUpVector() * Amount);
}
