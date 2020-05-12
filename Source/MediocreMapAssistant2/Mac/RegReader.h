// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RegReader.generated.h"

UCLASS()
class MEDIOCREMAPASSISTANT2_API URegReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	// Reads a registry key value
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Read Registry"), Category = "Registry Reader")
	static FString ReadRegistryValue(const FString& KeyName, const FString& ValueName);

	static bool IsWindows();

private:
	static const int MaxBufferSize = 256;
};
