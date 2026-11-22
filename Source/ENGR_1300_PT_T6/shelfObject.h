// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "testingClass.h"
#include "shelfObject.generated.h"

UCLASS()
class ENGR_1300_PT_T6_API AshelfObject : public AActor
{
	GENERATED_BODY()

public:
	testingClass object;
private:

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* hitbox;

public:
	// Sets default values for this actor's properties
	AshelfObject();

	void initialize(FString name, float price);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void onHitboxOverlap(
		UPrimitiveComponent* overlappedComponent,
		AActor* otherActor,
		UPrimitiveComponent* otherComponent,
		int32 otherBodyIndex,
		bool fromSweep,
		const FHitResult& sweepResult
	);
	void onHitboxEndOverlap(
		UPrimitiveComponent* overlappedComponent,
		AActor* otherActor,
		UPrimitiveComponent* otherComponent,
		int32 otherBodyIndex
	);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
