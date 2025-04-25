// Fill out your copyright notice in the Description page of Project Settings.


#include "Prologue.h"
#include "Components/TextBlock.h"
#include "TimerManager.h"

void UPrologue::NativeConstruct()
{
	Super::NativeConstruct();
    
	// 초기화
	if (StoryText)
	{
		StoryText->SetText(FText::FromString(TEXT("")));
	}
}

void UPrologue::StartTyping(const FString& NewText, float Speed)
{
	
	FullText = NewText;
	CurrentText = PreviousText;
	CurrentIndex = PreviousText.Len();
	TypingSpeed = Speed;
	PreviousText = NewText;
	IsTyping = true;

	// 타이머 시작
	GetWorld()->GetTimerManager().SetTimer(TypingTimer, this, &UPrologue::AddNextCharacter, TypingSpeed, true);
}

void UPrologue::AddNextCharacter()
{
	if (CurrentIndex < FullText.Len())
	{
		CurrentText.AppendChar(FullText[CurrentIndex]);
		if (StoryText)
		{
			StoryText->SetText(FText::FromString(CurrentText));
		}
		CurrentIndex++;
	}
	else
	{
		IsTyping = false;
		GetWorld()->GetTimerManager().ClearTimer(TypingTimer);
	}
}

void UPrologue::InitPreviousText()
{
	PreviousText = TEXT("");
}

void UPrologue::FastTyping()
{
	GetWorld()->GetTimerManager().ClearTimer(TypingTimer);
	CurrentText = FullText;

	if (StoryText)
	{
		StoryText->SetText(FText::FromString(CurrentText));
	}

	IsTyping = false;
	
}

