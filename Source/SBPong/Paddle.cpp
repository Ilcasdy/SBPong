// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/BoxComponent.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// components
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SetRootComponent(CollisionBox);
	VisualMesh->SetupAttachment(CollisionBox);

	
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetCollisionProfileName("Pawn");
	CollisionBox->SetNotifyRigidBodyCollision(true);
}


// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this,
		&APaddle::OnCollisionBoxBeginOverlap);
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}




