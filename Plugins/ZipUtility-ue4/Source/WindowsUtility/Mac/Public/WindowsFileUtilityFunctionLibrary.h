#pragma once

#include "WindowsFileUtilityFunctionLibrary.generated.h"

UCLASS(ClassGroup = WindowsFileUtility, Blueprintable)
class WINDOWSFILEUTILITY_API UWindowsFileUtilityFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

		
	UFUNCTION(BlueprintCallable, Category = WindowsFileUtility)
	static bool DoesFileExist(const FString& FullPath);

};
