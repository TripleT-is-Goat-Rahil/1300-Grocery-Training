// Fill out your copyright notice in the Description page of Project Settings.


#include "spaceManager.h"
#include "shelfObject.h"

// Sets default values
AspaceManager::AspaceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spaceHitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpaceHitbox"));

	RootComponent = spaceHitbox;

	spaceHitbox->SetBoxExtent(FVector(100.0f,100.0f,5.0f));

	spaceHitbox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	spaceHitbox->SetCollisionResponseToAllChannels(ECR_Ignore);
	spaceHitbox->SetCollisionResponseToChannel(ECC_WolrdDynamic, ECR_Overlap);

	spaceHitBox->SetGenerateOverlapEvents(true);

	spaceHitbox->OnComponentBeginOverlap.AddDynamic(
		this, &AspaceManager ::onObjectEnter
	);

	spaceHitbox->OnComponentEndOverlap.AddDynamic(
		this, &AspaceManager::onObjectExit
	);



}


void AspaceManager::onObjectEnter(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep
	const FHitREsult& SweepResult
)
{
	AshelfObject* detectedObject = Cast<AshelfObject>(OtherActor);

	if (detectedObject && !shelfObjects.Contains(detetectedObject))
	{
		shelfObjects.Add(detectedObject);
	}
}

void AspaceManager::onObjectExit(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex
)
{
	AshelfObject* detectedObject = Cast<AshelfObject>(OtherActor);

	if (!detectedObject) return;

	float objectX = OtherActor->GetActorLocation().X;
	float managerX = GetActorLocation().X;

	if (objectX < managerX) shelfObjects.Remove(detectedObject);
}

// Called when the game starts or when spawned
void AspaceManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AspaceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

