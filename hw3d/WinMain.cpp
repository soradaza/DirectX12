#include "Window.h"
#include "Exception.h"

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	try
	{
		Window wnd(800, 300, "Donkey Fart Box");

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (wnd.kbd.KeyIsPressed(VK_SPACE))
			{
				MessageBox(nullptr, "Something Happon!", "Space Key Was Pressed", MB_OK | MB_ICONEXCLAMATION);
			}
		}
		// check if GetMessage call itself borked
		if (gResult == -1)
		{
			return -1;
		}

		// wParam here is the value passed to PostQuitMessage
		return msg.wParam;
	}
	catch (const ChiliException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}

	catch (const std::exception& e)
	{
		return -1;
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}