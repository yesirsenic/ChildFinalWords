// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Ending.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class CHILDFINALWORDS_API UEnding : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void StartTyping(const FString& InFullText, float InCharInterval = 0.05f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTypingEnd = false;

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	FString FullText;
	FString CurrentText;
	int32 CurrentIndex = 0;

	float CharInterval = 0.05f;
	float TimeSinceLastChar = 0.0f;

	bool bIsTyping = false;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* EndingText;
	
	
};
