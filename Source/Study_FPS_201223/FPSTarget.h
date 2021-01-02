// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSTarget.generated.h"

UCLASS()
class STUDY_FPS_201223_API AFPSTarget : public AActor
{
	GENERATED_BODY()

	/** Box collision component */
	UPROPERTY(EditAnywhere, Category = Target)
	class UStaticMeshComponent* CollisionComp;
	
public:	
	// Sets default values for this actor's properties
	AFPSTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Destroy Actor when onhit
	UFUNCTION()
	void TargetOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
