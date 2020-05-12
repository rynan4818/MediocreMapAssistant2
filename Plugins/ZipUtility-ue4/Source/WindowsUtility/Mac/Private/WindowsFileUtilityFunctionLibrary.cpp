#include "../Public/WindowsFileUtilityFunctionLibrary.h"

UWindowsFileUtilityFunctionLibrary::UWindowsFileUtilityFunctionLibrary(const class FObjectInitializer& PCIP)
        : Super(PCIP)
{
}

bool UWindowsFileUtilityFunctionLibrary::DoesFileExist(const FString& FullPath)
{
	return FPaths::FileExists(FullPath);
}
