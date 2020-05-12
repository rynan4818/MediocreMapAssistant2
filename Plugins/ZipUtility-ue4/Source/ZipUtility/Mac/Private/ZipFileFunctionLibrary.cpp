#include "../Public/ZipFileFunctionLibrary.h"

UZipFileFunctionLibrary::UZipFileFunctionLibrary(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
}

UZipFileFunctionLibrary::~UZipFileFunctionLibrary()
{
}

UZipOperation* UZipFileFunctionLibrary::UnzipTo(const FString& ArchivePath, const FString& DestinationPath, UObject* ZipUtilityInterfaceDelegate, ZipUtilityCompressionFormat Format)
{
	return 0;
}
