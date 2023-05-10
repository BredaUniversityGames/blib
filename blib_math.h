#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <type_traits>

/*

	---------------------------------------------------------------------------------
											Todo
	Quat, translate, rotate, scale
	Ortho, view (lookAt), Unit testing
	
	---------------------------------------------------------------------------------
											Done
	Vec2: Constructors / arithmetic operators / bracket operators
	Vec3: Constructors / arithmetic operators / bracket operators
	Vec4: Constructors / arithmetic operators / bracket operators
	Mat3: Constructors / arithmetic operators / bracket operators
	Mat4: Constructors / arithmetic operators / bracket operators
	Quat: -

	Vector func: Dot product / Cross product / Length / Normalize
	Matrix func: Transpose / Perspective left-handed and right-handed, 0..1 and -1..1
	Func: Radians / Degrees
	Default types for float/double/uint/int vectors and matrices
	---------------------------------------------------------------------------------

*/
namespace blib
{

/*
	vec2 implementation
*/
template<typename T>
struct vec2_t
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	T x = 0, y = 0;

	/*
		Constructors
	*/
	vec2_t() = default;
	vec2_t(T scalar)
	{
		x = y = scalar;
	}
	vec2_t(T _x, T _y)
	{
		x = _x;
		y = _y;
	}

	/*
		Arithmetic operators
	*/
	constexpr vec2_t operator+(const vec2_t& other)
	{
		return { x + other.x, y + other.y };
	}
	constexpr vec2_t& operator+=(const vec2_t& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	constexpr vec2_t operator-(const vec2_t& other)
	{
		return { x - other.x, y - other.y };
	}
	constexpr vec2_t& operator-=(const vec2_t& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	constexpr vec2_t operator*(const vec2_t& other)
	{
		return { x * other.x, y * other.y };
	}
	constexpr vec2_t& operator*=(const vec2_t& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	constexpr vec2_t operator/(const vec2_t& other)
	{
		return { x / other.x, y / other.y };
	}
	constexpr vec2_t& operator/=(const vec2_t& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	/*
		Bracket operators
	*/
	T const& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 2);
		switch (index)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		}
	}

	T& operator[](uint32_t index)
	{
		return const_cast<T&>(static_cast<const vec2_t<T>&>(*this)[index]);
	}

};

/*
	Binary arithmetic operators (vec2_t)
*/
template<typename T>
constexpr vec2_t<T> operator+(const vec2_t<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar };
}
template<typename T>
constexpr vec2_t<T>& operator+=(const vec2_t<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	return *this;
}

template<typename T>
constexpr vec2_t<T> operator-(const vec2_t<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar };
}
template<typename T>
constexpr vec2_t<T>& operator-=(const vec2_t<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	return *this;
}

template<typename T>
constexpr vec2_t<T> operator*(const vec2_t<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar };
}
template<typename T>
constexpr vec2_t<T>& operator*=(const vec2_t<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	return *this;
}

template<typename T>
constexpr vec2_t<T> operator/(const vec2_t<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar };
}
template<typename T>
constexpr vec2_t<T>& operator/=(const vec2_t<T>& v0, T scalar)
{
	v0.x /= scalar;
	v0.y /= scalar;
	return *this;
}

/*
	vec3 implementation
*/
template<typename T>
struct vec3_t
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	T x = 0, y = 0, z = 0;

	/*
		Constructors
	*/
	vec3_t() = default;
	vec3_t(T scalar)
	{
		x = y = z = scalar;
	}
	vec3_t(T _x, T _y, T _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	/*
		Unary arithmetic operators
	*/
	constexpr vec3_t operator+(const vec3_t& other)
	{
		return { x + other.x, y + other.y, z + other.z };
	}
	constexpr vec3_t& operator+=(const vec3_t& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	constexpr vec3_t operator-(const vec3_t& other)
	{
		return { x - other.x, y - other.y, z - other.z };
	}
	constexpr vec3_t& operator-=(const vec3_t& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	constexpr vec3_t operator*(const vec3_t& other)
	{
		return { x * other.x, y * other.y, z * other.z };
	}
	constexpr vec3_t& operator*=(const vec3_t& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	constexpr vec3_t operator/(const vec3_t& other)
	{
		return { x / other.x, y / other.y, z / other.z };
	}
	constexpr vec3_t& operator/=(const vec3_t& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	/*
		Bracket operators
	*/
	T const& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 3);
		switch (index)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		}
	}

	T& operator[](uint32_t index)
	{
		return const_cast<T&>(static_cast<const vec3_t<T>&>(*this)[index]);
	}

};

/*
	Binary arithmetic operators (vec3_t)
*/
template<typename T>
constexpr vec3_t<T> operator+(const vec3_t<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar, v0.z + scalar };
}
template<typename T>
constexpr vec3_t<T>& operator+=(const vec3_t<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	v0.z += scalar;
	return *this;
}

template<typename T>
constexpr vec3_t<T> operator-(const vec3_t<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar, v0.z - scalar };
}
template<typename T>
constexpr vec3_t<T>& operator-=(const vec3_t<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	v0.z -= scalar;
	return *this;
}

template<typename T>
constexpr vec3_t<T> operator*(const vec3_t<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar, v0.z * scalar };
}
template<typename T>
constexpr vec3_t<T>& operator*=(const vec3_t<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	v0.z *= scalar;
	return *this;
}

template<typename T>
constexpr vec3_t<T> operator/(const vec3_t<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar, v0.z / scalar };
}
template<typename T>
constexpr vec3_t<T>& operator/=(const vec3_t<T>& v0, T scalar)
{
	v0.x /= scalar;
	v0.y /= scalar;
	v0.z /= scalar;
	return *this;
}

/*
	vec4 implementation
*/
template<typename T>
struct vec4_t
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	T x = 0, y = 0, z = 0, w = 0;

	/*
		Constructors
	*/
	vec4_t() = default;
	vec4_t(T scalar)
	{
		x = y = z = w = scalar;
	}
	vec4_t(T _x, T _y, T _z, T _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	/*
		Arithmetic operators
	*/
	constexpr vec4_t operator+(const vec4_t& other)
	{
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}
	constexpr vec4_t& operator+=(const vec4_t& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	constexpr vec4_t operator-(const vec4_t& other)
	{
		return { x - other.x, y - other.y, z - other.z, w - other.w };
	}
	constexpr vec4_t& operator-=(const vec4_t& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	constexpr vec4_t operator*(const vec4_t& other)
	{
		return { x * other.x, y * other.y, z * other.z, w * other.w };
	}
	constexpr vec4_t& operator*=(const vec4_t& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	constexpr vec4_t operator/(const vec4_t& other)
	{
		return { x / other.x, y / other.y, z / other.z, w / other.w };
	}
	constexpr vec4_t& operator/=(const vec4_t& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	/*
		Bracket operators
	*/
	T const& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 4);
		switch (index)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		}
	}

	T& operator[](uint32_t index)
	{
		return const_cast<T&>(static_cast<const vec4_t<T>&>(*this)[index]);
	}

};

/*
	Binary arithmetic operators (vec4_t)
*/
template<typename T>
constexpr vec4_t<T> operator+(const vec4_t<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar, v0.z + scalar, v0.w + scalar };
}
template<typename T>
constexpr vec4_t<T>& operator+=(const vec4_t<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	v0.z += scalar;
	v0.w += scalar;
	return *this;
}

template<typename T>
constexpr vec4_t<T> operator-(const vec4_t<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar, v0.z - scalar, v0.w - scalar };
}
template<typename T>
constexpr vec4_t<T>& operator-=(const vec4_t<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	v0.z -= scalar;
	v0.w -= scalar;
	return *this;
}

template<typename T>
constexpr vec4_t<T> operator*(const vec4_t<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar, v0.z * scalar, v0.w * scalar };
}
template<typename T>
constexpr vec4_t<T>& operator*=(const vec4_t<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	v0.z *= scalar;
	v0.w *= scalar;
	return *this;
}

template<typename T>
constexpr vec4_t<T> operator/(const vec4_t<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar, v0.z / scalar, v0.w / scalar };
}
template<typename T>
constexpr vec4_t<T>& operator/=(const vec4_t<T>& v0, T scalar)
{
	v0.x /= scalar;
	v0.y /= scalar;
	v0.z /= scalar;
	v0.w /= scalar;
	return *this;
}

/*
	mat3 implementation
*/
template<typename T>
struct mat3_t
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	vec3_t<T> value[3];

	/*
		Constructors
	*/
	mat3_t()
	{
		value[0] = { 1, 0, 0 };
		value[0] = { 0, 1, 0 };
		value[0] = { 0, 0, 1 };
	}
	mat3_t(T scalar)
	{
		value[0] = scalar;
		value[1] = scalar;
		value[2] = scalar;
	}
	mat3_t(const vec3_t<T>& v0, const vec3_t<T>& v1, const vec3_t<T>& v2)
	{
		value[0] = v0;
		value[1] = v1;
		value[2] = v2;
	}

	/*
		Arithmetic operators
	*/
	constexpr mat3_t operator+(const mat3_t<T>& other)
	{
		return { value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2] };
	}
	constexpr mat3_t& operator+=(const mat3_t<T>& other)
	{
		value[0] += other.value[0];
		value[1] += other.value[1];
		value[2] += other.value[2];
		return *this;
	}

	constexpr mat3_t operator-(const mat3_t<T>& other)
	{
		return { value[0] - other.value[0], value[1] - other.value[1], value[2] - other.value[2] };
	}
	constexpr mat3_t& operator-=(const mat3_t<T>& other)
	{
		value[0] -= other.value[0];
		value[1] -= other.value[1];
		value[2] -= other.value[2];
		return *this;
	}

	constexpr mat3_t operator*(const mat3_t<T>& other)
	{
		return { value[0] * other.value[0], value[1] * other.value[1], value[2] * other.value[2] };
	}
	constexpr mat3_t& operator*=(const mat3_t<T>& other)
	{
		value[0] *= other.value[0];
		value[1] *= other.value[1];
		value[2] *= other.value[2];
		return *this;
	}

	constexpr mat3_t operator/(const mat3_t<T>& other)
	{
		return { value[0] / other.value[0], value[1] / other.value[1], value[2] / other.value[2] };
	}
	constexpr mat3_t& operator/=(const mat3_t<T>& other)
	{
		value[0] /= other.value[0];
		value[1] /= other.value[1];
		value[2] /= other.value[2];
		return *this;
	}

	/*
		Bracket operators
	*/
	const vec3_t<T>& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 3);
		return value[index];
	}

	vec3_t<T>& operator[](uint32_t index)
	{
		return const_cast<vec3_t<T>&>(static_cast<const mat3_t<T>&>(*this)[index]);
	}

};

/*
	mat4 implementation
*/
template<typename T>
struct mat4_t
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	vec4_t<T> value[4];

	/*
		Constructors
	*/
	mat4_t()
	{
		value[0] = { 1, 0, 0, 0 };
		value[1] = { 0, 1, 0, 0 };
		value[2] = { 0, 0, 1, 0 };
		value[3] = { 0, 0, 0, 1 };
	}
	mat4_t(T scalar)
	{
		value[0] = scalar;
		value[1] = scalar;
		value[2] = scalar;
		value[3] = scalar;
	}
	mat4_t(const vec4_t<T>& v0, const vec4_t<T>& v1, const vec4_t<T>& v2, const vec4_t<T>& v3)
	{
		value[0] = v0;
		value[1] = v1;
		value[2] = v2;
		value[3] = v3;
	}

	/*
		Arithmetic operators
	*/
	constexpr mat4_t operator+(const mat4_t<T>& other)
	{
		return { value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2], value[3] + other.value[3] };
	}
	constexpr mat4_t& operator+=(const mat4_t<T>& other)
	{
		value[0] += other.value[0];
		value[1] += other.value[1];
		value[2] += other.value[2];
		value[3] += other.value[3];
		return *this;
	}

	constexpr mat4_t operator-(const mat4_t<T>& other)
	{
		return { value[0] - other.value[0], value[1] - other.value[1], value[2] - other.value[2], value[3] - other.value[3] };
	}
	constexpr mat4_t& operator-=(const mat4_t<T>& other)
	{
		value[0] -= other.value[0];
		value[1] -= other.value[1];
		value[2] -= other.value[2];
		value[3] -= other.value[3];
		return *this;
	}

	constexpr mat4_t operator*(const mat4_t<T>& other)
	{
		return { value[0] * other.value[0], value[1] * other.value[1], value[2] * other.value[2], value[3] * other.value[3] };
	}
	constexpr mat4_t& operator*=(const mat4_t<T>& other)
	{
		value[0] *= other.value[0];
		value[1] *= other.value[1];
		value[2] *= other.value[2];
		value[3] *= other.value[3];
		return *this;
	}

	constexpr mat4_t operator/(const mat4_t<T>& other)
	{
		return { value[0] / other.value[0], value[1] / other.value[1], value[2] / other.value[2], value[3] / other.value[3] };
	}
	constexpr mat4_t& operator/=(const mat4_t<T>& other)
	{
		value[0] /= other.value[0];
		value[1] /= other.value[1];
		value[2] /= other.value[2];
		value[3] /= other.value[3];
		return *this;
	}

	/*
		Bracket operators
	*/
	const vec4_t<T>& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 4);
		return value[index];
	}

	vec4_t<T>& operator[](uint32_t index)
	{
		return const_cast<vec4_t<T>&>(static_cast<const mat4_t<T>&>(*this)[index]);
	}

};

/*

	Vector functions

*/

template<typename T>
inline constexpr T dot(const vec2_t<T>& v0, const vec2_t<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y;
}

template<typename T>
inline constexpr T dot(const vec3_t<T>& v0, const vec3_t<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

template<typename T>
inline constexpr T dot(const vec4_t<T>& v0, const vec4_t<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
}

template<typename T>
inline constexpr vec3_t<T> cross(const vec3_t<T>& v0, const vec3_t<T>& v1)
{
	return {
		v0.y * v1.z - v0.z * v1.y,
		v0.z * v1.x - v0.x * v1.z,
		v0.x * v1.y - v0.y * v1.x
	};
}

template<typename T>
inline constexpr T length(const vec2_t<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr T length(const vec3_t<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr T length(const vec4_t<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr vec2_t<T> normalize(const vec2_t<T>& v0)
{
	return v0 * (1 / length(v0));
}

template<typename T>
inline constexpr vec3_t<T> normalize(const vec3_t<T>& v0)
{
	return v0 * (1 / length(v0));
}

template<typename T>
inline constexpr vec4_t<T> normalize(const vec4_t<T>& v0)
{
	return v0 * (1 / length(v0));
}

/*

	Additional useful functions

*/
template<typename T>
inline constexpr T degrees(T rad)
{
	return (180 * rad) / M_PI;
}

template<typename T>
inline constexpr T radians(T deg)
{
	return (M_PI * deg) / 180;
}

/*

	Matrix functions

*/

template<typename T>
inline constexpr mat3_t<T> transpose(const mat3_t<T>& mat3)
{
	mat3_t<T> newMat3 = mat3;
	newMat3[0][1] = mat3[1][0];
	newMat3[0][2] = mat3[2][0];
	newMat3[1][0] = mat3[0][1];
	newMat3[1][2] = mat3[2][1];
	newMat3[2][0] = mat3[0][2];
	newMat3[2][1] = mat3[1][2];

	return mat3;
}

template<typename T>
inline constexpr mat4_t<T> transpose(const mat4_t<T>& mat4)
{
	mat4_t<T> newMat4 = mat4;
	mat4[0][1] = mat4[1][0];
	mat4[0][2] = mat4[2][0];
	mat4[0][3] = mat4[3][0];
	mat4[1][0] = mat4[0][1];
	mat4[1][2] = mat4[2][1];
	mat4[1][3] = mat4[3][1];
	mat4[2][0] = mat4[0][2];
	mat4[2][1] = mat4[1][2];
	mat4[2][3] = mat4[3][2];

	return newMat4;
}

// Todo: Add translate, rotate, scale here

/*

	Perspective projection matrix functions

*/

// Creates a right-handed perspective projection, with the normalized device z coordinate mapped between 0 and 1
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveRH_ZO(T fov, T aspectRatio, T near, T far)
{
	mat4_t<T> mat;

	T g = tan(fov / 2);
	T k = far / (far - near);

	mat[0][0] = g / aspectRatio;
	mat[1][1] = g;
	mat[2][2] = k;
	mat[2][3] = -near * k;
	mat[3][2] = 1;
	mat[3][3] = 0;

	return mat;
}

// Creates a right-handed perspective projection, with the normalized device z coordinate mapped between 0 and 1
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveRH_ZO(T fov, T width, T height, T near, T far)
{
	return perspectiveRH_ZO<T>(fov, width / height, near, far);
}

// Creates a right-handed perspective projection, with the normalized device z coordinate mapped between -1 and 1 (OpenGL)
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveRH_NO(T fov, T aspectRatio, T near, T far)
{
	mat4_t<T> mat;

	T g = tan(fov / 2);

	mat[0][0] = g / aspectRatio;
	mat[1][1] = g;
	mat[2][2] = (far + near) / (near - far);
	mat[2][3] = (2 * far * near) / (near - far);
	mat[3][2] = -1;
	mat[3][3] = 0;

	return mat;
}

// Creates a right-handed perspective projection, with the normalized device z coordinate mapped between -1 and 1 (OpenGL)
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveRH_NO(T fov, T width, T height, T near, T far)
{
	return perspectiveRH_NO<T>(fov, width / height, near, far);
}

// Creates a left-handed perspective projection, with the normalized device z coordinate mapped between 0 and 1 (DirectX)
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveLH_ZO(T fov, T aspectRatio, T near, T far)
{
	mat4_t<T> mat;

	T g = tan(fov / 2);
	T k = far / (far - near);

	mat[0][0] = -g / aspectRatio;
	mat[1][1] = -g;
	mat[2][2] = k;
	mat[2][3] = -near * k;
	mat[3][2] = 1;
	mat[3][3] = 0;

	return mat;
}

// Creates a left-handed perspective projection, with the normalized device z coordinate mapped between 0 and 1 (DirectX)
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveLH_ZO(T fov, T width, T height, T near, T far)
{
	return perspectiveLH_ZO<T>(fov, width / height, near, far);
}

// Creates a left-handed perspective projection, with the normalized device z coordinate mapped between -1 and 1
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveLH_NO(T fov, T aspectRatio, T near, T far)
{
	mat4_t<T> mat;

	T g = tan(fov / 2);

	mat[0][0] = -g / aspectRatio;
	mat[1][1] = -g;
	mat[2][2] = (far + near) / (near - far);
	mat[2][3] = (2 * far * near) / (near - far);
	mat[3][2] = -1;
	mat[3][3] = 0;

	return mat;
}

// Creates a left-handed perspective projection, with the normalized device z coordinate mapped between -1 and 1
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspectiveLH_NO(T fov, T width, T height, T near, T far)
{
	return perspectiveLH_NO<T>(fov, width / height, near, far);
}

// By default this constructs a right-handed perspective projection, with the normalized device z coordinate mapped between -1 and 1 (OpenGL)
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspective(T fov, T aspectRatio, T near, T far)
{
	return perspectiveRH_NO<T>(fov, aspectRatio, near, far);
}

// By default this constructs a right-handed perspective projection, with the normalized device z coordinate mapped between -1 and 1 (OpenGL)
// FOV must be in radians
template<typename T>
constexpr mat4_t<T> perspective(T fov, T width, T height, T near, T far)
{
	return perspective<T>(fov, width / height, near, far);
}

/*

	Orthographic projection matrix functions

*/


/*

	View matrix functions

*/

// Float vectors and matrices
using vec2 = vec2_t<float>;
using vec3 = vec3_t<float>;
using vec4 = vec4_t<float>;
using mat3 = mat3_t<float>;
using mat4 = mat4_t<float>;

// Double vectors and matrices
using dvec2 = vec2_t<double>;
using dvec3 = vec3_t<double>;
using dvec4 = vec4_t<double>;
using dmat3 = mat3_t<double>;
using dmat4 = mat4_t<double>;

// Unsigned integer vectors and matrices
using uvec2 = vec2_t<unsigned int>;
using uvec3 = vec3_t<unsigned int>;
using uvec4 = vec4_t<unsigned int>;
using umat3 = mat3_t<unsigned int>;
using umat4 = mat4_t<unsigned int>;

// Integer vectors and matrices
using ivec2 = vec2_t<int>;
using ivec3 = vec3_t<int>;
using ivec4 = vec4_t<int>;
using imat3 = mat3_t<int>;
using imat4 = mat4_t<int>;

}