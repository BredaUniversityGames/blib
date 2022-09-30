#pragma once
#define WIN32_LEAN_AND_MEAN
#pragma warning(push ,0)
#include <Windows.h>
#pragma warning(pop)
#include <string>
//struct HDC__; TODO: Forward declare 		HWND m_handle; RECT m_windowRect; !!!!!!!!!!!!
namespace blib {
	class WindowWin32
	{
	public:
		static WindowWin32 Create(uint32_t width, uint32_t height);
		void HandleEvents(MSG msg);
		void SetTitle(std::string title);
		HWND GetWindowsHandle();
		void SetFullscreen(bool fullscreen);
		void CleanUp();
		bool shouldClose = false;
		uint32_t screenWidth = 0;
		uint32_t screenHeight = 0;

	private:
		HWND m_handle = nullptr;
		RECT m_windowRect = RECT();
		bool m_fullscreen = false;
	};
}