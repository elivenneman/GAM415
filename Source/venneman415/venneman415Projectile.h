// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "venneman415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)
class Avenneman415Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	/** Mesh component */
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ballMesh;

	/** Base material */
	UPROPERTY(EditAnywhere)
	UMaterial* baseMat;

	/** Randomized color */
	UPROPERTY()
	FLinearColor randColor;

	/** Projectile material */
	UPROPERTY(EditAnywhere)
	UMaterialInterface* projMat;

	/** Dynamic material instance */
	UPROPERTY()
	UMaterialInstanceDynamic* dmiMat;
	
	/** Randomzied color for niagara system */
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* colorP;

public:
	Avenneman415Projectile();

protected:
	virtual void BeginPlay();

public:
	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

