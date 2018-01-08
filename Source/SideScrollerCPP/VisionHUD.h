/*
* VisionHUD: Heads-Up Display class for machine vision projects with UnrealEngine4
*
* Adapted from https://answers.unrealengine.com/questions/193827/how-to-get-texture-pixels-using-utexturerendertarg.html
*
* Copyright (C) 2017 Simon D. Levy
*
* MIT License
*/

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Character.h"
#include "Engine/TextureRenderTarget2D.h"

#include "VisionAlgorithm.h"

#include "VisionHUD.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLERCPP_API AVisionHUD : public AHUD
{
	GENERATED_BODY()

protected:

	// Arbirary params for display
	const float LEFTX = 45.f;
	const float TOPY = 90.f;
	const FLinearColor BORDER_COLOR = FLinearColor::Yellow;
	const float BORDER_WIDTH = 2.0f;

	// These should agree with the specification of the render target in your blueprint
	const wchar_t * RENDER_TARGET_NAME = L"/Game/T_Minimap";
	const EPixelFormat RENDER_TARGET_PIXEL_FORMAT = PF_B8G8R8A8;

	// Access to MiniMap camera stream
	UCameraComponent* MiniMapCameraComponent;
	UTextureRenderTarget2D* MiniMapTextureRenderTarget;
	FRenderTarget* MiniMapRenderTarget;
	TArray<FColor> MiniMapSurfData;

	AVisionHUD();

	~AVisionHUD();
	
	virtual void DrawHUD() override;

	void drawBorder(float lx, float uy, float rx, float by);

	// Computed by constructor, used in DrawHUD
	int rows;
	int cols;

	// 24-bit color
	uint8_t* imagergb;

	// implementation of your vision algorithm
	VisionAlgorithm* algorithm;
};
