// Fill out your copyright notice in the Description page of Project Settings.


#include "ElevatorBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "CppBpTestProjectCharacter.h"

// Sets default values
AElevatorBase::AElevatorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	ElevatorBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ElevatorBasePlatform"));
	ElevatorBaseMesh->SetupAttachment(DefaultSceneRoot);

	ElevatorTriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("ElevatorTriggerVolume"));
	ElevatorTriggerVolume->SetupAttachment(DefaultSceneRoot);
	ElevatorTriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AElevatorBase::OnElevatorTrigger);
}

// Called when the game starts or when spawned
void AElevatorBase::BeginPlay()
{
	Super::BeginPlay();
	StartHeight = GetActorLocation().Z;
	EndHeight = StartHeight + MovementHeight;
}

// Called every frame
void AElevatorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElevatorBase::OnElevatorTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACppBpTestProjectCharacter* CharRef = Cast<ACppBpTestProjectCharacter>(OtherActor);
	if (CharRef != nullptr) {
		OnTriggered();
	}
}