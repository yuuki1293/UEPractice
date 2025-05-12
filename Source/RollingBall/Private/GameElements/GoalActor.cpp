// Fill out your copyright notice in the Description page of Project Settings.


#include "GameElements/GoalActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Character/BallPlayer.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoalActor::AGoalActor()
{
	// StaticMeshComponentを追加し、RootComponentに設定する
	Goal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = Goal;

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/RollingBall/Enviroment/Meshes/S_Goal"));

	// StaticMeshをStaticMeshComponentに設定する
	Goal->SetStaticMesh(Mesh);

	// SphereCollisionを追加する
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(RootComponent);

	// Radiusを設定する
	Sphere->SetSphereRadius(72.0f);

	// OnComponentBeginOverlapをBindする
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AGoalActor::OnSphereBeginOverlap);
}

// Called when the game starts or when spawned
void AGoalActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoalActor::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 接触したActorがBallPlayerか判定する
	if (const ABallPlayer* Player = Cast<ABallPlayer>(OtherActor))
	{
		// 遷移するLevelをLoadする
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadLevel);
	}
}
