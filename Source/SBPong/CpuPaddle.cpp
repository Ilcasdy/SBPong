// Fill out your copyright notice in the Description page of Project Settings.


#include "CpuPaddle.h"
#include "Kismet/GameplayStatics.h"

void ACpuPaddle::BeginPlay()
{
    Super::BeginPlay();

    

}

void ACpuPaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Ball = Cast<ABall>(UGameplayStatics::GetActorOfClass(GetWorld(), ABall::StaticClass()));
    if (Ball) 
    {
        FVector BallLocation = Ball->GetActorLocation();
        BallLocation.Y = GetActorLocation().Y;
        BallLocation.X = GetActorLocation().X;
        FVector lerp = FMath::Lerp(FVector(GetActorLocation()), BallLocation, 0.015f);
        SetActorLocation(lerp);
    }

}
