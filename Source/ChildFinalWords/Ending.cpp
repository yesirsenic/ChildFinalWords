// Fill out your copyright notice in the Description page of Project Settings.


#include "Ending.h"
#include "Components/TextBlock.h"

void UEnding::StartTyping(const FString& InFullText, float InCharInterval)
{
	FullText = InFullText;
	CurrentText.Empty();
	CurrentIndex = 0;
	CharInterval = InCharInterval;
	TimeSinceLastChar = 0.0f;
	bIsTyping = true;
}

void UEnding::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!bIsTyping || CurrentIndex >= FullText.Len())
		return;

	TimeSinceLastChar += InDeltaTime;

	if (TimeSinceLastChar >= CharInterval)
	{
		TimeSinceLastChar = 0.0f;

		// 현재 글자 하나 추가
		CurrentText.AppendChar(FullText[CurrentIndex]);
		++CurrentIndex;

		if (EndingText)
		{
			EndingText->SetText(FText::FromString(CurrentText));
		}

		if (CurrentIndex >= FullText.Len())
		{
			bIsTyping = false;
			IsTypingEnd = true;
		}
	}
}