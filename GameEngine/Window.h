#pragma once
#include <cassert>;
#include "sfwdraw.h"

#define INIT_ASSERT assert(IsInitialized && "Window is not initialized!");

class Window
{
private:
	Window() : IsInitialized(false){}
	bool IsInitialized;
	unsigned Width, Height;
public:
	//Only allow one instance
	static Window &Instance() 
	{
		static Window Instance;
		return Instance;
	}

	bool Init(unsigned width = 600, unsigned height = 800, const char *Title = "GameEngine")
	{
		sfw::initContext(width, height, Title);
		return IsInitialized;
	}
	bool Step()
	{
		INIT_ASSERT;
		return sfw::initContext();
	}

	void Term() 
	{
		INIT_ASSERT;
		sfw::termContext();
		IsInitialized = false;
	}

	unsigned GetWidth() { INIT_ASSERT; return Width; }
	unsigned GetHeight() { INIT_ASSERT; return Height; }
	bool GetIsInitialized() { return IsInitialized; }
};