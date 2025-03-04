// Fill out your copyright notice in the Description page of Project Settings.


#include "EndZone.h"
#include "Components/BoxComponent.h"

// Sets default values
AEndZone::AEndZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	SetRootComponent(CollisionBox);

}

// Called when the game starts or when spawned
void AEndZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEndZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

