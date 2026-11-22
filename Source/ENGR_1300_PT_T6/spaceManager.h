// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "spaceManager.generated.h"

class AshelfObject;

UCLASS()
class ENGR_1300_PT_T6_API AspaceManager : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AspaceManager();

protected:
	// Called when the game starts or when spawned

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> spaceHitbox;

	UPROPERTY()
	TArray<TObjectPtr<AshelfObject>> shelfObjects;

	UFUNCTION()
	void onObjectEnter(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	UFUNCTION()
	void onObjectExit(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex
	); 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
