// Fill out your copyright notice in the Description page of Project Settings.


#include "shelfObject.h"

// Sets default values
AshelfObject::AshelfObject()
	: object()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AshelfObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AshelfObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

