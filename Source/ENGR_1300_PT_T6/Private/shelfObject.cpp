// Fill out your copyright notice in the Description page of Project Settings.


#include "shelfObject.h"

// Sets default values
AshelfObject::AshelfObject()
	: object()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));

	RootComponent = hitbox;

	hitbox->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));

	hitbox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	hitbox->SetCollisionResponseToAllChannels(ECR_Overlap);

}

// Called when the game starts or when spawned
void AshelfObject::BeginPlay()
{
	AActor::BeginPlay();
	
}

// Called every frame
void AshelfObject::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

}

void AshelfObject::initialize(FString name, float price)
{
	object.setName(name);
	object.setPrice(price);
}
