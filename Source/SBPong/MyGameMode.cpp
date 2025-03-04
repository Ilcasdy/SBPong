// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "GameCamera.h"
#include "Ball.h"
#include "BallSpawner.h"
#include "Kismet/GameplayStatics.h"

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC) 
    {
        // Find the first instance of a game camera
        AGameCamera* TheCamera = Cast<AGameCamera>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameCamera::StaticClass()));

        if (TheCamera)
        {
           PC->SetViewTarget(TheCamera);

            //PC->SetViewTargetWithBlend(TheCamera, 3.0f, VTBlend_Cubic);
        }
    }
}

void AMyGameMode::Tick(float DeltaTime)
{

    Super::Tick(DeltaTime);


}
