#pragma once

#include "ZipFileFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum ZipUtilityCompressionFormat
{
	COMPRESSION_FORMAT_UNKNOWN,
	COMPRESSION_FORMAT_SEVEN_ZIP,
	COMPRESSION_FORMAT_ZIP,
	COMPRESSION_FORMAT_GZIP,
	COMPRESSION_FORMAT_BZIP2,
	COMPRESSION_FORMAT_RAR,
	COMPRESSION_FORMAT_TAR,
	COMPRESSION_FORMAT_ISO,
	COMPRESSION_FORMAT_CAB,
	COMPRESSION_FORMAT_LZMA,
	COMPRESSION_FORMAT_LZMA86
};


UENUM(BlueprintType)
enum ZipUtilityCompressionLevel
{
	COMPRESSION_LEVEL_NONE,
	COMPRESSION_LEVEL_FAST,
	COMPRESSION_LEVEL_NORMAL
};

UCLASS(ClassGroup = ZipUtility, Blueprintable)
class ZIPUTILITY_API UZipFileFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	~UZipFileFunctionLibrary();
	
	/* Unzips archive at destination path. Automatically determines compression if unknown. Calls ZipUtilityInterface progress events. */
	UFUNCTION(BlueprintCallable, Category = ZipUtility)
	static UZipOperation* UnzipTo(const FString& ArchivePath, const FString& DestinationPath, UObject* ZipUtilityInterfaceDelegate, ZipUtilityCompressionFormat format = COMPRESSION_FORMAT_UNKNOWN);
};


