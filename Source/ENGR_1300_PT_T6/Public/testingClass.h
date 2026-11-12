// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class ENGR_1300_PT_T6_API testingClass
{
private:
	FString nameObject;
	float priceObject;
	TArray<testingClass*> touchingLeft;
	TArray<testingClass*> touchingRight;
	TArray<testingClass*> touchingTop;
	TArray<testingClass*> touchingBottom;
public:
	testingClass(FString nameObject, float priceObject);
	~testingClass();
	float getPrice() const;
	FString getName() const;
	void addTouchingLeft(testingClass* object);
	void addTouchingRight(testingClass* object);
	void addTouchingTop(testingClass* object);
	void addTouchingBottom(testingClass* object);
	void removeTouchingLeft(testingClass* object);
	void removeTouchingRight(testingClass* object);
	void removeTouchingTop(testingClass* object);
	void removeTouchingBottom(testingClass* object);
	const TArray<testingClass*>& getTouchingLeft() const;
	const TArray<testingClass*>& getTouchingRight() const;
	const TArray<testingClass*>& getTouchingTop() const;
	const TArray<testingClass*>& getTouchingBottom() const;
};
