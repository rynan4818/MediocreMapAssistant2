// Fill out your copyright notice in the Description page of Project Settings.


#include "RegReader.h"

bool URegReader::IsWindows()
{
	return false;
}

FString URegReader::ReadRegistryValue(const FString& KeyName, const FString& ValueName)
{
	return FString(getenv("HOME"));
}
