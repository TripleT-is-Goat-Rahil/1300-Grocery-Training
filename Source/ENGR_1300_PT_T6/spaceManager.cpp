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
	spaceHitbox->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);

	spaceHitbox->SetGenerateOverlapEvents(true);

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
	bool bFromSweep, 
	const FHitResult& SweepResult
)
{
	AshelfObject* detectedObject = Cast<AshelfObject>(OtherActor);

	if (detectedObject && !shelfObjects.Contains(detectedObject))
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


// Called every frame
void AspaceManager::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

}

void AspaceManager::setRuleset(bool price, bool ratio, bool position)
{
	if (price == true)
	{
		isPriceRuleset = true;
	}
	if (ratio == true)
	{
		isRatioRuleset = true;
	}
	if (position == true)
	{
		isPositionRuleset = true;
	}
}

int AspaceManager::priceCounter() {
	int total = 0;
	for (AshelfObject* item : shelfObjects)
	{
		if (!item) continue;
		total += item->object.getPrice();
	}
	return total;
}

bool AspaceManager::ratioChecker(int objectOne, FString name, int objectTwo, FString nameTwo) {
	int  objectOneTotal = 0;
	int objectTwoTotal = 0;

	for (AshelfObject* item : shelfObjects)
	{
		if (item->object.getName() == name) objectOneTotal++;
		if (item->object.getName() == nameTwo) objectTwoTotal++;
	}
	if (objectOneTotal * objectOne == objectTwoTotal * objectTwo)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AspaceManager::positionChecker(bool top, bool right, bool left, bool front, bool bottom, bool back, FString objectOne, FString objectTwo) 
{
	int objectOneSide = 0;
	int objectTwoSide = 0;
	for (AshelfObject* item : shelfObjects) 
	{
		if (!item) continue;

		if (top) 
		{
			if (item->object.getName() == objectOne) {
				for (testingClass* subject : item->object.getTouchingBottom())
				{
					if (subject->getName()==objectTwo) objectOneSide++;
				}
			}
			if (item->object.getName() == objectTwo) {
				for (testingClass* subject : item->object.getTouchingTop())
				{
					if (subject->getName() == objectTwo) objectTwoSide++;
				}
			}
		}
	}
}