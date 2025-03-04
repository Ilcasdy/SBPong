// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "EndZone.h"
#include "PlayerEndZone.h"
#include "CpuEndZone.h"
#include "PongGameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "BallSpawner.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// components
	Root = CreateDefaultSubobject<USphereComponent>(TEXT("RootSphereComponent"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	SetRootComponent(Root);
	VisualMesh->SetupAttachment(RootComponent);

	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Root->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Root->SetCollisionProfileName("Pawn");
	Root->SetNotifyRigidBodyCollision(true);

	if (!ProjectileMovementComponent)
	{
		// Use this component to drive this projectile's movement.
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		// values for the projectile movement component
		ProjectileMovementComponent->InitialSpeed = 500.0f;
		ProjectileMovementComponent->MaxSpeed = 1000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = false;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 1.2f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
		ProjectileMovementComponent->Friction = 0.0f;
		ProjectileMovementComponent->Velocity = FVector(0.5, 0, 0.5);
		// after 30 seconds the ball will respawn if no score
		InitialLifeSpan = 30.0f;
	}
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	Root->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnCollisionSphereBeginOverlap);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// This function handles when an endzone is met
void ABall::OnCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// if the ball overlaps with an endzone actor, increase the respective score, despawn and then respawn the ball
	AEndZone* EndZone = Cast<AEndZone>(OtherActor);
	if (EndZone) {
		APlayerEndZone* EZ = Cast<APlayerEndZone>(EndZone);
		APongGameStateBase* GS = Cast<APongGameStateBase>(GetWorld()->GetGameState());
		if (EZ) {
			GS->IncrementCpuScore();
			Destroy();
			ABallSpawner* spawner = Cast<ABallSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ABallSpawner::StaticClass()));
			spawner->SpawnBall();
		}
		else {
			GS->IncrementPlayerScore();
			Destroy();
			ABallSpawner* spawner = Cast<ABallSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ABallSpawner::StaticClass()));
			spawner->SpawnBall();
		}
	}
}
// this function handles when the ball lifespawn timer is expired
void ABall::LifeSpanExpired()
{
	Destroy();
	ABallSpawner* spawner = Cast<ABallSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), ABallSpawner::StaticClass()));
	spawner->SpawnBall();
}


