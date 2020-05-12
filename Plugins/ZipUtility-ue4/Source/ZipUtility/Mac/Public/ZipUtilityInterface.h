// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ZipUtilityInterface.generated.h"

UENUM(BlueprintType)
enum EZipUtilityCompletionState
{
	SUCCESS,
	FAILURE_NOT_FOUND,
	FAILURE_UNKNOWN
};


UINTERFACE(MinimalAPI)
class UZipUtilityInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ZIPUTILITY_API IZipUtilityInterface
{
	GENERATED_IINTERFACE_BODY()

public:

        /**
        * Called when whole process is complete (e.g. unzipping completed on archive)
        */
        UFUNCTION(BlueprintNativeEvent, Category = ZipUtilityProgressEvents)
                void OnDone(const FString& archive, EZipUtilityCompletionState CompletionState);

};
