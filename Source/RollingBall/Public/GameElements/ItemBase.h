// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class URotatingMovementComponent;

UCLASS()
class ROLLINGBALL_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Item取得用の関数 */
	virtual void GetItem();

public:	
	/** Item用のStaticMesh : ItemMesh */
	UPROPERTY(VisibleAnywhere, Category = Item)
	TObjectPtr<UStaticMeshComponent> ItemMesh;

	/** 接触判定用のCollision : Sphere */
	UPROPERTY(VisibleAnywhere, Category = Item)
	TObjectPtr<USphereComponent> Sphere;

	/** 回転用のComponent */
	UPROPERTY(VisibleAnywhere, Category = Item)
	TObjectPtr<URotatingMovementComponent> RotatingMovement;

private:
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
