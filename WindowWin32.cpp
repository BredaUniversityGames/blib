#include "WindowWin32.h"

#pragma warning(push ,0)
#include <cassert> //assert
#pragma warning(pop)

// In order to define a function called CreateWindow, the Windows macro needs to
// be undefined.
#if defined(CreateWindow)
#undef CreateWindow
#endif



using namespace blib;

static bool g_IsWindowRegistered = false;

static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

static void RegisterWindowClass(HINSTANCE hInst, const wchar_t* windowClassName)
{
    // Register a window class for creating our render window with.
    WNDCLASSEXW windowClass = {};

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = WndProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInst;
    windowClass.hIcon = ::LoadIcon(hInst, IDI_WINLOGO);
    windowClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    windowClass.lpszMenuName = NULL;
    windowClass.lpszClassName = windowClassName;
    windowClass.hIconSm = ::LoadIcon(hInst, IDI_WINLOGO);

    static ATOM atom = ::RegisterClassExW(&windowClass);
    assert(atom > 0);
    g_IsWindowRegistered = true;
}

static HWND CreateWindow(const wchar_t* windowClassName, HINSTANCE hInst,
    const wchar_t* windowTitle, uint32_t width, uint32_t height)
{
    int screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = ::GetSystemMetrics(SM_CYSCREEN);

    RECT windowRect = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
    ::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

    int windowWidth = windowRect.right - windowRect.left;
    int windowHeight = windowRect.bottom - windowRect.top;

    // Center the window within the screen. Clamp to 0, 0 for the top-left corner.
    int windowX = std::max<int>(0, (screenWidth - windowWidth) / 2);
    int windowY = std::max<int>(0, (screenHeight - windowHeight) / 2);

    HWND hWnd = ::CreateWindowExW(
        NULL,
        windowClassName,
        windowTitle,
        WS_OVERLAPPEDWINDOW,
        windowX,
        windowY,
        windowWidth,
        windowHeight,
        NULL,
        NULL,
        hInst,
        nullptr
    );

    assert(hWnd && "Failed to create window");

    return hWnd;
}

WindowWin32 WindowWin32::Create(uint32_t width, uint32_t height)
{
    if (!g_IsWindowRegistered)
    {
        RegisterWindowClass(0, L"WindowWin32");
    }
    WindowWin32 windowWin32;
    windowWin32.screenWidth = width;
    windowWin32.screenHeight = height;
    windowWin32.m_handle = CreateWindow(L"WindowWin32", 0, L"Blib", windowWin32.screenWidth, windowWin32.screenHeight);

    ShowWindow(windowWin32.m_handle, SW_NORMAL);
    return windowWin32;
}

void WindowWin32::HandleEvents(MSG msg)
{
    SetWindowLongPtr(m_handle, GWLP_USERDATA, (LONG_PTR)this);
   
	    switch (msg.message)
	    {
        case WM_KEYDOWN:
        {
            switch (msg.wParam)
            {
            case VK_ESCAPE:
                shouldClose = true;
                break;
            case VK_F11:
                SetFullscreen(!m_fullscreen);
                break;
            }
        }
        break;
        default:
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
	    	break;
	    }
}

void WindowWin32::SetTitle(std::string title)
{
    SetWindowTextA(m_handle, title.c_str());
}

HWND WindowWin32::GetWindowsHandle()
{
    return m_handle;
}

void WindowWin32::SetFullscreen(bool fullscreen)
{
    if (m_fullscreen != fullscreen)
    {
        m_fullscreen = fullscreen;

        if (m_fullscreen) // Switching to fullscreen.
        {
            // Store the current window dimensions so they can be restored 
            // when switching out of fullscreen state.
            ::GetWindowRect(m_handle, &m_windowRect);
            // Set the window style to a borderless window so the client area fills
            // the entire screen.
            UINT windowStyle = WS_OVERLAPPEDWINDOW & ~(WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);

            ::SetWindowLongW(m_handle, GWL_STYLE, windowStyle);
            // Query the name of the nearest display device for the window.
            // This is required to set the fullscreen dimensions of the window
            // when using a multi-monitor setup.
            HMONITOR hMonitor = ::MonitorFromWindow(m_handle, MONITOR_DEFAULTTONEAREST);
            MONITORINFOEX monitorInfo = {};
            monitorInfo.cbSize = sizeof(MONITORINFOEX);
            ::GetMonitorInfo(hMonitor, &monitorInfo);
            ::SetWindowPos(m_handle, HWND_TOP,
                monitorInfo.rcMonitor.left,
                monitorInfo.rcMonitor.top,
                monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left,
                monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top,
                SWP_FRAMECHANGED | SWP_NOACTIVATE);

            ::ShowWindow(m_handle, SW_MAXIMIZE);
        }
        else
        {
            // Restore all the window decorators.
            ::SetWindowLong(m_handle, GWL_STYLE, WS_OVERLAPPEDWINDOW);

            ::SetWindowPos(m_handle, HWND_NOTOPMOST,
                m_windowRect.left,
                m_windowRect.top,
                m_windowRect.right - m_windowRect.left,
                m_windowRect.bottom - m_windowRect.top,
                SWP_FRAMECHANGED | SWP_NOACTIVATE);

            ::ShowWindow(m_handle, SW_NORMAL);
        }
    }
}

void WindowWin32::CleanUp()
{
    ::DestroyWindow(m_handle);
    //::UnregisterClass(wc.lpszClassName, wc.hInstance);
}

#if defined( STV_IMGUI_IMPL )
// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
#endif

static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
#if defined( STV_IMGUI_IMPL )
    if (ImGui_ImplWin32_WndProcHandler(hwnd, message, wParam, lParam))
        return true;
#endif

    WindowWin32* window = (WindowWin32*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    switch (message)
    {
    case WM_SIZE:
    {
        RECT clientRect = {};
        if (window != NULL) { //TODO: Remove the null check later
            ::GetClientRect(window->GetWindowsHandle(), &clientRect);


            uint32_t width = clientRect.right - clientRect.left;
            uint32_t height = clientRect.bottom - clientRect.top;

            if (window->screenWidth != width || window->screenHeight != height)
            {
                window->screenWidth = max(1u, width);
                window->screenHeight = max(1u, height);
            }
        }
        break;
    }
    case WM_CLOSE:
        window->shouldClose = true;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        break;
    default:
        return ::DefWindowProcW(hwnd, message, wParam, lParam);
    }
    return 0;
}
