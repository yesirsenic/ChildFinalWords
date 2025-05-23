// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	CharacterMoveState = ECharacterMoveState::Idle;
	CharacterState = ECharacterState::Move;
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainCharacter::SetMoveState(ECharacterMoveState ChangeState)
{
		CharacterMoveState = ChangeState;
}

void AMainCharacter::SetState(ECharacterState ChangeState)
{
	CharacterState = ChangeState;
}

void AMainCharacter::ResetInput(APlayerController* MainPlayerController)
{
	if (MainPlayerController)
	{
		MainPlayerController->FlushPressedKeys(); 
	}
}







