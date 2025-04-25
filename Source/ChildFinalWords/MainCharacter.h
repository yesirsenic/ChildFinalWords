// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UENUM(BlueprintType)
enum class ECharacterMoveState : uint8
{
	Idle        UMETA(DisplayName = "Idle"),
	Walking    UMETA(DisplayName = "Walking"),
	Running     UMETA(DisplayName = "Running"),
};

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	Move  UMETA(DisplayName = "Move"),
	Rooding UMETA(DisplayName = "Rooding"),
	Dizziness UMETA(DisplayName = "Dizziness"),
	Attacked UMETA(DisplayName = "Attacked")
	
};

UCLASS()
class CHILDFINALWORDS_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetMoveState(ECharacterMoveState ChangeState);

	UFUNCTION(BlueprintCallable)
	void SetState(ECharacterState ChangeState);

	UFUNCTION(BlueprintCallable)
	void ResetInput(APlayerController* MainPlayerController);

private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Anim", meta = (AllowPrivateAccess = "true"))
	ECharacterMoveState CharacterMoveState = ECharacterMoveState::Idle;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Anim", meta = (AllowPrivateAccess = "true"))
	ECharacterState CharacterState = ECharacterState::Move;

};
