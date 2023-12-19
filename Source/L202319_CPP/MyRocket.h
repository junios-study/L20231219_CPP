// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyRocket.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class L202319_CPP_API AMyRocket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyRocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadOnly, visibleAnywhere, Category = "Component")
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(BlueprintReadOnly, visibleAnywhere, Category = "Component")
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(BlueprintReadOnly, visibleAnywhere, Category = "Component")
	TObjectPtr<UProjectileMovementComponent> Movement;

	UFUNCTION()
	void ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION(BlueprintImplementableEvent)
	void CPPToCallBP(int64 Damage);

	UFUNCTION(BlueprintNativeEvent)
	void ExistCPPToCallBP(int64 Damage);
	void ExistCPPToCallBP_Implementation(int64 Damage);
	
};
