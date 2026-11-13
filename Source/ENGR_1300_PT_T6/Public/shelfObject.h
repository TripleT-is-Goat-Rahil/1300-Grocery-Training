// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "testingClass.h"
#include "shelfObject.generated.h"
UCLASS()
class ENGR_1300_PT_T6_API AshelfObject : public AActor
{
	GENERATED_BODY()
	
private:
	testingClass object;
public:	
	// Sets default values for this actor's properties
	AshelfObject();
	void initialize(FString name,float price);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
