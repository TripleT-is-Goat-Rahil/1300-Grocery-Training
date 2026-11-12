// Fill out your copyright notice in the Description page of Project Settings.


#include "testingClass.h"

testingClass::testingClass(FString name, float price)
{
	this->nameObject = name;
	this->priceObject = price;
}

testingClass::~testingClass()
{
}


float testingClass::getPrice() const
{
	return priceObject;
}

FString testingClass::getName() const 
{
	return nameObject;
}

void testingClass::addTouchingLeft(testingClass* object)
{
	if (object && !touchingLeft.Contains(object))
	{
		touchingLeft.Add(object);
	}
}

void testingClass::removeTouchingLeft(testingClass* object)
{
	if (object && touchingLeft.Contains(object)) 
	{
		touchingLeft.RemoveSingle(object);
	}
}

void testingClass::addTouchingRight(testingClass* object)
{
	if (object && !touchingRight.Contains(object))
	{
		touchingRight.Add(object);
	}
}

void testingClass::removeTouchingRight(testingClass* object)
{
	if (object && touchingRight.Contains(object))
	{
		touchingRight.RemoveSingle(object);
	}
}

void testingClass::addTouchingTop(testingClass* object)
{
	if (object && !touchingTop.Contains(object))
	{
		touchingTop.Add(object);
	}
}

void testingClass::removeTouchingTop(testingClass* object)
{
	if (object && touchingTop.Contains(object))
	{
		touchingTop.RemoveSingle(object);
	}
}

void testingClass::addTouchingBottom(testingClass* object)
{
	if (object && !touchingBottom.Contains(object))
	{
		touchingBottom.Add(object);
	}
}

void testingClass::removeTouchingBottom(testingClass* object)
{
	if (object && touchingBottom.Contains(object))
	{
		touchingBottom.RemoveSingle(object);
	}
}

const TArray<testingClass*>& testingClass::getTouchingLeft() const
{
	return touchingLeft;
}

const TArray<testingClass*>& testingClass::getTouchingRight() const
{
	return touchingRight;
}

const TArray<testingClass*>& testingClass::getTouchingTop() const
{
	return touchingTop;
}

const TArray<testingClass*>& testingClass::getTouchingBottom() const
{
	return touchingBottom;
}