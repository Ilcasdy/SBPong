// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Paddle.h"
#include "Ball.h"
#include "CpuPaddle.generated.h"

/**
 * 
 */
UCLASS()
class SBPONG_API ACpuPaddle : public APaddle
{
	GENERATED_BODY()

public:

	ABall* Ball;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
