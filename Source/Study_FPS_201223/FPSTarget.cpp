// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSTarget.h"
#include "Components/BoxComponent.h"

// Sets default values
AFPSTarget::AFPSTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Use a Box as a simple collision representation
	CollisionComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetComp"));
	//CollisionComp->InitBoxExtent(FVector(10,10,10));
	CollisionComp->BodyInstance.SetCollisionProfileName("Target");
	CollisionComp->OnComponentHit.AddDynamic(this, &AFPSTarget::TargetOnHit);
	CollisionComp->SetupAttachment(RootComponent);

	//RootComponent = CollisionComp;
}

// Called when the game starts or when spawned
void AFPSTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Destroy Actor when onhit
void AFPSTarget::TargetOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Log, TEXT("HIT"));
	if ((OtherActor != this) && OtherComponent->BodyInstance.GetCollisionProfileName() == "Projectile")
	{	
		Destroy();
	}
}

