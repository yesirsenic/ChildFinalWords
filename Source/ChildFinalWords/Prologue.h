// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Prologue.generated.h"

/**
 * 
 */
UCLASS()
class CHILDFINALWORDS_API UPrologue : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void StartTyping(const FString& NewText, float Speed = 0.1f);

	UFUNCTION(BlueprintCallable)
	void InitPreviousText();

	UFUNCTION(BlueprintCallable)
	void FastTyping();
	
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UTextBlock* StoryText;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Prologue", meta = (EditCondition = "CurrentText"))
	bool IsTyping = false;

protected:
	virtual void NativeConstruct() override;
	
private:
	void AddNextCharacter();
	

	FString FullText;
	FString CurrentText;
	FString PreviousText;
	int32 CurrentIndex = 0;

	UPROPERTY(EditAnywhere,Category="Prologue", meta = (EditCondition = "CurrentText"))
	float TypingSpeed = 3.f;

	

	FTimerHandle TypingTimer;
};
