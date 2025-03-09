// Copyright Epic Games, Inc. All Rights Reserved.

#include "venneman415GameMode.h"
#include "venneman415Character.h"
#include "UObject/ConstructorHelpers.h"

Avenneman415GameMode::Avenneman415GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
