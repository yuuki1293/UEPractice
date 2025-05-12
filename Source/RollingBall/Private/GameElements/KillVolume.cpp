// Fill out your copyright notice in the Description page of Project Settings.


#include "GameElements/KillVolume.h"
#include "Components/BoxComponent.h"

// Sets default values
AKillVolume::AKillVolume()
{
	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;
	
	KillVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));

	// BoxComponentをRootComponentにAttachする
	KillVolume->SetupAttachment(RootComponent);

	// BoxComponentのOnComponentBegineOverlapに関数「OnBoxBeginOverlap」を関連づける
	KillVolume->OnComponentBeginOverlap.AddDynamic(this, &AKillVolume::OnBoxBeginOverlap);
}

// Called when the game starts or when spawned
void AKillVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKillVolume::OnConstruction(const FTransform& Transform)
{
	// KillVolumeのBox Extentを変更する
	KillVolume->SetBoxExtent(BoxExtent);
}

void AKillVolume::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 接触したActorがBallPlayerか判定する
	if (ABallPlayer* Player = Cast<ABallPlayer>(OtherActor))
	{
		// GameModeを取得して、InGameGameModeにCastする
		if (AInGameGameMode* GameMode = Cast<AInGameGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
		{
			// KillPlayerを呼び出してPlayerを破棄する
			GameMode->KillPlayer(Player);
		}
	}
}
