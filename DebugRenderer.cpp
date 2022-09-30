#include "DebugRenderer.h"
#define WIN32_LEAN_AND_MEAN
#pragma warning(push ,0)
#include <Windows.h>
#include <gl\gl.h>
#pragma warning(pop)
#include "WindowWin32.h"
#include <iostream>

using namespace blib;

static WindowWin32*		g_window = nullptr;
static HDC__*			g_windowDC = nullptr;
static uint32_t				g_count = 0;
static const uint32_t		g_maxCount = 4096;
static DrawItem			g_drawItems[g_maxCount];
static const uint32_t		g_numSegments = 50;

static void OpenGLSetScreenspace(uint32_t width, uint32_t height) {
	glMatrixMode(GL_PROJECTION);
	float a = 2.0f / (float)width;
	float b = 2.0f / (float)height;
	float projection_matrix[] = {
		 a,  0, 0, 0,
		 0,  b, 0, 0,
		 0,  0, 1, 0,
		-1, -1, 0, 1,
	};
	glLoadMatrixf(projection_matrix);
}

void DebugRenderer::InitOpenGL(WindowWin32* window)
{
	g_window = window;
	g_windowDC = GetDC(g_window->GetWindowsHandle());

	PIXELFORMATDESCRIPTOR desiredPixelFormat = {};
	desiredPixelFormat.nSize = sizeof(desiredPixelFormat);
	desiredPixelFormat.nVersion = 1;
	desiredPixelFormat.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
	desiredPixelFormat.cColorBits = 24;
	desiredPixelFormat.cAlphaBits = 8;
	desiredPixelFormat.iLayerType = PFD_MAIN_PLANE;

	int suggestedPixelFormatIndex = ChoosePixelFormat(g_windowDC, &desiredPixelFormat);
	PIXELFORMATDESCRIPTOR suggestedPixelFormat;
	DescribePixelFormat(g_windowDC, suggestedPixelFormatIndex, sizeof(suggestedPixelFormat), &suggestedPixelFormat);
	SetPixelFormat(g_windowDC, suggestedPixelFormatIndex, &suggestedPixelFormat);
	
	HGLRC openGLRC = wglCreateContext(g_windowDC);
	if(wglMakeCurrent(g_windowDC, openGLRC))
	{
		std::string versionString = std::string((const char*)glGetString(GL_VERSION));
		std::cout << "OpenGL: Success! (" << versionString << ")\n";
	}
	else
	{
		std::cout << "OpenGL: wglMakeCurrent\n";
	}

	OpenGLSetScreenspace(window->screenWidth, window->screenHeight);

}

void DebugRenderer::Render()
{
	glViewport(0, 0, g_window->screenWidth, g_window->screenHeight); //TODO: if statement to check if w/h updated

	glClear(GL_COLOR_BUFFER_BIT);

	unsigned int rgba = 0x2E8B57ff;
	glClearColor(((rgba >> 24) & 0xff) / 255.0f,
		((rgba >> 16) & 0xff) / 255.0f,
		((rgba >> 8) & 0xff) / 255.0f,
		(rgba & 0xff) / 255.0f);

	//Render loop
	for(size_t i = 0; i < g_count; i++)
	{
		DrawItem item = g_drawItems[i];
		if(item.glMode == GL_LINE)
		{
			glBegin(GL_LINES);
			glColor4f(item.color.x, item.color.y, item.color.z, 1.0f);
			glVertex3f(item.x, item.y, 0);
			glVertex3f(item.z, item.w, 0);
			glEnd();
		}
		else if (item.glMode == GL_QUADS)
		{
			glBegin(GL_QUADS);
			glColor4f(item.color.x, item.color.y, item.color.z, 1.0f);
			glVertex3f(item.x, item.y, 0);
			glVertex3f(item.x + item.z, item.y, 0);
			glVertex3f(item.x + item.z, item.y + item.w, 0);
			glVertex3f(item.x, item.y + item.w, 0);
			glEnd();
			glColor4f(1, 1, 1, 1);
		}
		else if (item.glMode == GL_LINE_LOOP)
		{
			glBegin(GL_LINE_LOOP);
			glColor4f(item.color.x, item.color.y, item.color.z, 1.0f);
			for (size_t j = 0; j < g_numSegments; j++) {
				float theta = 2.0f * 3.14159265359f * float(j) / float(g_numSegments);
				float x = item.z * cosf(theta); 
				float y = item.z * sinf(theta);
				glVertex2f(x + item.x, y + item.y);
			}
			glEnd();
		}
	}

	g_count = 0;
	SwapBuffers(g_windowDC);
}

void DebugRenderer::CleanUp()
{
	ReleaseDC(g_window->GetWindowsHandle(), g_windowDC);
}

void DebugRenderer::DrawLine(float startX, float startY, float endX, float endY, vec3 color)
{
	DrawItem drawItem = { startX, startY, endX, endY, color, GL_LINE };
	if(g_count < g_maxCount) g_drawItems[g_count++] = drawItem;
}

void DebugRenderer::DrawRect(float x, float y, float width, float height, vec3 color)
{
	DrawLine(x, y, x + width, y, color);
	DrawLine(x + width, y, x + width, y + height, color);
	DrawLine(x + width, y + height, x, y + height, color);
	DrawLine(x, y + height, x, y, color);
}

void DebugRenderer::DrawFilledRect(float x, float y, float width, float height, vec3 color)
{
	DrawItem drawItem = { x, y, width, height, color, GL_QUADS };
	if (g_count < g_maxCount) g_drawItems[g_count++] = drawItem;
}

void DebugRenderer::DrawCircle(float centerX, float centerY, float radius, vec3 color)
{
	DrawItem drawItem = { centerX, centerY, radius, -1.0f, color, GL_LINE_LOOP };
	if (g_count < g_maxCount) g_drawItems[g_count++] = drawItem;
}
