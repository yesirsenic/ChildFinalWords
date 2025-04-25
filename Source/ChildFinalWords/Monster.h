// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Monster.generated.h"

UENUM(BlueprintType)
enum class MonsterState : uint8
{
	Idle  UMETA(DisplayName = "Idle"),
	Move	UMETA(DisplayName = "Move"),
	Damaged	UMETA(DisplayName = "Damaged"),
	Tracking	UMETA(DisplayName = "Tracking"),
	FastMove	UMETA(DisplayName = "FastMove")
	
};


UCLASS()
class CHILDFINALWORDS_API AMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetState(MonsterState ChangeState);

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "State", meta = (AllowPrivateAccess = "true"))
	MonsterState MonsterCurrentState = MonsterState::Idle;

};
