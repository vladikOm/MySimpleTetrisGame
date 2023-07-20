#include "header//Tools.h"

namespace Tools
{
	// A function to prevent resizing of the window.
	void   DisableWindowResizing()
	{
		HWND consoleWindow = GetConsoleWindow();
		SetWindowLong(
			consoleWindow, GWL_STYLE,
			GetWindowLong(consoleWindow, GWL_STYLE)); //& ~WS_MAXIMIZEBOX & WS_SIZEBOX

	}

	//A function to disable the cursor in the window.
	void TurnOffConsole()
	{
		HWND hwnd = GetConsoleWindow();
		ShowWindow(hwnd, SW_HIDE);
	}
	void TurnConsole()
	{
		//Displaying the console window
		HWND consoleWindow = GetConsoleWindow();
		ShowWindow(consoleWindow, SW_SHOW);
	}

// Setting descriptors for standard input, output, and errors.
	void SetSetingStandart() 
	{
		
		HANDLE consoleInput = GetStdHandle(STD_INPUT_HANDLE);
		HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		HANDLE consoleError = GetStdHandle(STD_ERROR_HANDLE);
		SetStdHandle(STD_INPUT_HANDLE, consoleInput);
		SetStdHandle(STD_OUTPUT_HANDLE, consoleOutput);
		SetStdHandle(STD_ERROR_HANDLE, consoleError);
	}
	void SetTools()
	{
		TurnOffConsole();      
		//TurnConsole();
		// DisableWindowResizing();
		//void SetSetingStandart();
		//ShowCursor(false);
	}
}