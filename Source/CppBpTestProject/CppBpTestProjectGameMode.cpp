// Copyright Epic Games, Inc. All Rights Reserved.

#include "CppBpTestProjectGameMode.h"
#include "CppBpTestProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACppBpTestProjectGameMode::ACppBpTestProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
