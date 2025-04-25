// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChildFinalWordsGameMode.h"
#include "ChildFinalWordsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AChildFinalWordsGameMode::AChildFinalWordsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
