// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElevatorBase.generated.h"

UCLASS()
class CPPBPTESTPROJECT_API AElevatorBase : public AActor
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	class USceneComponent* DefaultSceneRoot{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	class UStaticMeshComponent* ElevatorBaseMesh{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	class UBoxComponent* ElevatorTriggerVolume{ nullptr };

private:
	float StartHeight{};
	float EndHeight{};

protected:

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Setup")
	float MovementHeight{ 200.0f };
	
	// Returns starting height of the elevator (world space)
	UFUNCTION(BlueprintPure)
	float GetStartHeight() const { return StartHeight; }

	// Returns ending height of the elevator (world space)
	UFUNCTION(BlueprintPure)
	float GetEndHeight() const { return EndHeight; }

	UFUNCTION(BlueprintImplementableEvent)
	void OnTriggered();

private:
	UFUNCTION()
	void OnElevatorTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Sets default values for this actor's properties
	AElevatorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
