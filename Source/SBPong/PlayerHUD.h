// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class SBPONG_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* PlayerScoreText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* CpuScoreText;



	UFUNCTION()
	FText SetPlayerScoreText();

	UFUNCTION()
	FText SetCpuScoreText();
	
};
