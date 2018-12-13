#pragma once

/*
* VisionAlgorithm.h: Abstract threaded machine-vision class for UnrealEngine4
*
* Copyright (C) 2017 Simon D. Levy
*
* MIT License
*/

#include "Engine.h"

#include "Runtime/Core/Public/HAL/Runnable.h"
#include "GameFramework/Actor.h"

#include <opencv2/core.hpp>

#include <cstdint>

/**
*  Abstract machine-vision class.
*/
class VisionAlgorithm  {

public:

	/**
	 * Constructor gets HUD and its coordinates for possible display.
	*/
    VisionAlgorithm(int width, int height,
		AHUD * hud, int leftx, int topy) : _hud(hud), _leftx(leftx), _topy(topy) { }

	/**
	 * Mandatory virtual destructor to avoid compiler errors.
	*/
	virtual ~VisionAlgorithm() { }

	/**
	* Your implementing class should provide this method.
	* @param imagebgr OpenCV Mat containing color image in OpenCV's standard BGR order
	*/
	virtual void perform(cv::Mat & imagebgr) = 0;

protected:

	int _leftx;
	int _topy;

	AHUD * _hud;
};

