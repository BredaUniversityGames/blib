#pragma once
#include <cstdint>
#include "Vector.h"
namespace blib {

	struct DrawItem
	{
		uint32_t x;
		uint32_t y;
		uint32_t z;
		uint32_t w;
		vec3 color;
		uint32_t glMode;
	};

	class WindowWin32;
	class DebugRenderer
	{
	public:
		static void InitOpenGL(WindowWin32* window);
		static void Render();
		static void CleanUp();
		static void DrawLine(float startX, float startY, float endX, float endY, vec3 color);
		static void DrawRect(float x, float y, float width, float height, vec3 color);
		static void DrawFilledRect(float x, float y, float width, float height, vec3 color);
		static void DrawCircle(float centerX, float centerY, float radius, vec3 color);
	};
}