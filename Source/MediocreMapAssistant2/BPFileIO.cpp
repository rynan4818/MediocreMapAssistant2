// Fill out your copyright notice in the Description page of Project Settings.

#include "BPFileIO.h"

#include "ModuleManager.h"
#include "FileHelper.h"

#include "ImageUtils.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"

bool UBPFileIO::VerifyOrCreateDirectory(const FString & TestDir)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// Directory Exists?
	if (!PlatformFile.DirectoryExists(*TestDir))
	{
		PlatformFile.CreateDirectory(*TestDir);

		if (!PlatformFile.DirectoryExists(*TestDir))
		{
			return false;
		}
	}
	return true;
}

bool UBPFileIO::VerifyDirectory(const FString & TestDir)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// Directory Exists?
	if (!PlatformFile.DirectoryExists(*TestDir))
	{
		return false;
	}
	return true;
}

FString UBPFileIO::CheckImageFormatMatches(const FString & TestPath)
{
	FString unknownProblem = "Something's weird with your cover image, and i don't know what it is.";
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

	TArray<uint8> FileData;
	if (!FFileHelper::LoadFileToArray(FileData, *TestPath))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load file"));
		return unknownProblem;
	}

	EImageFormat fileFormat = ImageWrapperModule.DetectImageFormat(FileData.GetData(), FileData.Num());

	if ((TestPath.EndsWith(".png") && fileFormat == EImageFormat::PNG) ||
		((TestPath.EndsWith(".jpg") || TestPath.EndsWith(".jpeg")) && (fileFormat == EImageFormat::JPEG || fileFormat == EImageFormat::GrayscaleJPEG)))
	{
		return unknownProblem;
	} else if (!TestPath.EndsWith(".png") && !TestPath.EndsWith(".jpg") && !TestPath.EndsWith(".jpeg")) {
		return "Your cover image needs to be a jpg or png and end with .jpg, .jpeg or .png";
	}

	FString fileFormatStr;
	switch (fileFormat) {
		case EImageFormat::BMP:
			fileFormatStr = "BMP";
			break;
		case EImageFormat::PNG:
			fileFormatStr = "PNG";
			break;
		case EImageFormat::JPEG:
		case EImageFormat::GrayscaleJPEG:
			fileFormatStr = "JPG";
			break;
		case EImageFormat::ICO:
			fileFormatStr = "ICO";
			break;
		case EImageFormat::EXR:
			fileFormatStr = "EXR";
			break;
		case EImageFormat::ICNS:
			fileFormatStr = "ICNS";
			break;
		case EImageFormat::Invalid:
		default:
			fileFormatStr = "Unknown";
	}

	return "Your cover image appears to be a " + fileFormatStr + " file, but the extension does not match";
}

TArray<FString> UBPFileIO::FindAllDirectories(const FString & TestDir)
{
	TArray<FString> result;
	IFileManager& FileManager = IFileManager::Get();
	FString FinalPath = TestDir + "/*";

	FileManager.FindFiles(result, *FinalPath, false, true);
	return result;
}

TArray<FString> UBPFileIO::FindAllFiles(const FString & TestDir)
{
	TArray<FString> result;
	IFileManager& FileManager = IFileManager::Get();
	FString FinalPath = TestDir + "/*";

	FileManager.FindFiles(result, *FinalPath, true, false);
	return result;
}

bool UBPFileIO::VerifyFile(const FString & TestFile)
{
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*TestFile))
	{
		return true;
	}
	return false;
}

bool UBPFileIO::RenameOrMoveFile(const FString & InputFile, const FString & OutputFile)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*InputFile))
	{
		return false;
	}

	if (!FPlatformFileManager::Get().GetPlatformFile().MoveFile(*OutputFile, *InputFile))
	{
		return false;
	}

	return true;
}

bool UBPFileIO::CopyFile(const FString & File, const FString& OutputDirectory, const FString& newName)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (PlatformFile.FileExists(*File))
	{
		if (PlatformFile.DirectoryExists(*OutputDirectory))
		{
			PlatformFile.CopyFile(*FString(OutputDirectory + "/" + newName), *File);
			return true;
		}
	}
	return false;
}

bool UBPFileIO::DeleteFile(const FString & File)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*File))
	{
		return false;
	}

	return true;
}

bool UBPFileIO::DeleteDirectory(const FString & Directory)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*Directory))
	{
		return false;
	}

	return true;
}

int UBPFileIO::getFileSize(const FString & File)
{
	return FPlatformFileManager::Get().GetPlatformFile().FileSize(*File);
}

int UBPFileIO::getTimestamp(const FString & File)
{
	return FPlatformFileManager::Get().GetPlatformFile().GetTimeStamp(*File).ToUnixTimestamp();
}