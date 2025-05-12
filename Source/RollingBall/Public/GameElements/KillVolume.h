// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Framework/InGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "KillVolume.generated.h"

class UBoxComponent;

UCLASS()
class ROLLINGBALL_API AKillVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKillVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ConstructionScript
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	/** Box Collisionのサイズを設定する変数 **/
	UPROPERTY(EditAnywhere, Category = "Kill Volume")
	FVector BoxExtent = FVector(32.0f, 32.0f, 32.0f);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	/** Default Scene Root **/
	UPROPERTY(VisibleAnywhere, Category = KillVolume, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	/** PlayerをKillするAreaを設定するBox Collision **/
	UPROPERTY(VisibleAnywhere, Category = KillVolume, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> KillVolume;

	UFUNCTION()
    void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
