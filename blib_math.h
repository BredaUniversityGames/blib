#pragma once
#include <type_traits>

/*

	Todo: Quat, translate, rotate, scale, using typename aliases, eliminate bracket operator code duplication

	Vec2: Constructors / arithmetic operators / bracket operators
	Vec3: Constructors / arithmetic operators / bracket operators
	Vec4: Constructors / arithmetic operators / bracket operators
	Mat3: Constructors / arithmetic operators / bracket operators
	Mat4: Constructors / arithmetic operators / bracket operators
	Quat: -

	Func: Dot product / Cross product / Length / Normalize

*/
namespace blib
{

/*
	vec2 implementation
*/
template<typename T>
struct default_vec2
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	T x = 0, y = 0;

	/*
		Constructors
	*/
	default_vec2() = default;
	default_vec2(T scalar)
	{
		x = y = scalar;
	}
	default_vec2(T _x, T _y)
	{
		x = _x;
		y = _y;
	}

	/*
		Arithmetic operators
	*/
	constexpr default_vec2 operator+(const default_vec2& other)
	{
		return { x + other.x, y + other.y };
	}
	constexpr default_vec2& operator+=(const default_vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	constexpr default_vec2 operator-(const default_vec2& other)
	{
		return { x - other.x, y - other.y };
	}
	constexpr default_vec2& operator-=(const default_vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	constexpr default_vec2 operator*(const default_vec2& other)
	{
		return { x * other.x, y * other.y };
	}
	constexpr default_vec2& operator*=(const default_vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	constexpr default_vec2 operator/(const default_vec2& other)
	{
		return { x / other.x, y / other.y };
	}
	constexpr default_vec2& operator/=(const default_vec2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	/*
		Bracket operators
	*/
	T& operator[](uint32_t index)
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

};

/*
	Binary arithmetic operators (default_vec2)
*/
template<typename T>
constexpr default_vec2<T> operator+(const default_vec2<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar };
}
template<typename T>
constexpr default_vec2<T>& operator+=(const default_vec2<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	return *this;
}

template<typename T>
constexpr default_vec2<T> operator-(const default_vec2<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar };
}
template<typename T>
constexpr default_vec2<T>& operator-=(const default_vec2<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	return *this;
}

template<typename T>
constexpr default_vec2<T> operator*(const default_vec2<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar };
}
template<typename T>
constexpr default_vec2<T>& operator*=(const default_vec2<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	return *this;
}

template<typename T>
constexpr default_vec2<T> operator/(const default_vec2<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar };
}
template<typename T>
constexpr default_vec2<T>& operator/=(const default_vec2<T>& v0, T scalar)
{
	v0.x /= scalar;
	v0.y /= scalar;
	return *this;
}

/*
	vec3 implementation
*/
template<typename T>
struct default_vec3
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	T x = 0, y = 0, z = 0;

	/*
		Constructors
	*/
	default_vec3() = default;
	default_vec3(T scalar)
	{
		x = y = z = scalar;
	}
	default_vec3(T _x, T _y, T _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	/*
		Unary arithmetic operators
	*/
	constexpr default_vec3 operator+(const default_vec3& other)
	{
		return { x + other.x, y + other.y, z + other.z };
	}
	constexpr default_vec3& operator+=(const default_vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	constexpr default_vec3 operator-(const default_vec3& other)
	{
		return { x - other.x, y - other.y, z - other.z };
	}
	constexpr default_vec3& operator-=(const default_vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	constexpr default_vec3 operator*(const default_vec3& other)
	{
		return { x * other.x, y * other.y, z * other.z };
	}
	constexpr default_vec3& operator*=(const default_vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	constexpr default_vec3 operator/(const default_vec3& other)
	{
		return { x / other.x, y / other.y, z / other.z };
	}
	constexpr default_vec3& operator/=(const default_vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	/*
		Bracket operators
	*/
	T& operator[](uint32_t index)
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

};

/*
	Binary arithmetic operators (default_vec3)
*/
template<typename T>
constexpr default_vec3<T> operator+(const default_vec3<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar, v0.z + scalar };
}
template<typename T>
constexpr default_vec3<T>& operator+=(const default_vec3<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	v0.z += scalar;
	return *this;
}

template<typename T>
constexpr default_vec3<T> operator-(const default_vec3<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar, v0.z - scalar };
}
template<typename T>
constexpr default_vec3<T>& operator-=(const default_vec3<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	v0.z -= scalar;
	return *this;
}

template<typename T>
constexpr default_vec3<T> operator*(const default_vec3<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar, v0.z * scalar };
}
template<typename T>
constexpr default_vec3<T>& operator*=(const default_vec3<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	v0.z *= scalar;
	return *this;
}

template<typename T>
constexpr default_vec3<T> operator/(const default_vec3<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar, v0.z / scalar };
}
template<typename T>
constexpr default_vec3<T>& operator/=(const default_vec3<T>& v0, T scalar)
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
struct default_vec4
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	T x = 0, y = 0, z = 0, w = 0;

	/*
		Constructors
	*/
	default_vec4() = default;
	default_vec4(T scalar)
	{
		x = y = z = w = scalar;
	}
	default_vec4(T _x, T _y, T _z, T _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	/*
		Arithmetic operators
	*/
	constexpr default_vec4 operator+(const default_vec4& other)
	{
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}
	constexpr default_vec4& operator+=(const default_vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	constexpr default_vec4 operator-(const default_vec4& other)
	{
		return { x - other.x, y - other.y, z - other.z, w - other.w };
	}
	constexpr default_vec4& operator-=(const default_vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	constexpr default_vec4 operator*(const default_vec4& other)
	{
		return { x * other.x, y * other.y, z * other.z, w * other.w };
	}
	constexpr default_vec4& operator*=(const default_vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	constexpr default_vec4 operator/(const default_vec4& other)
	{
		return { x / other.x, y / other.y, z / other.z, w / other.w };
	}
	constexpr default_vec4& operator/=(const default_vec4& other)
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
	T& operator[](uint32_t index)
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

};

/*
	Binary arithmetic operators (default_vec4)
*/
template<typename T>
constexpr default_vec4<T> operator+(const default_vec4<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar, v0.z + scalar, v0.w + scalar };
}
template<typename T>
constexpr default_vec4<T>& operator+=(const default_vec4<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	v0.z += scalar;
	v0.w += scalar;
	return *this;
}

template<typename T>
constexpr default_vec4<T> operator-(const default_vec4<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar, v0.z - scalar, v0.w - scalar };
}
template<typename T>
constexpr default_vec4<T>& operator-=(const default_vec4<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	v0.z -= scalar;
	v0.w -= scalar;
	return *this;
}

template<typename T>
constexpr default_vec4<T> operator*(const default_vec4<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar, v0.z * scalar, v0.w * scalar };
}
template<typename T>
constexpr default_vec4<T>& operator*=(const default_vec4<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	v0.z *= scalar;
	v0.w *= scalar;
	return *this;
}

template<typename T>
constexpr default_vec4<T> operator/(const default_vec4<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar, v0.z / scalar, v0.w / scalar };
}
template<typename T>
constexpr default_vec4<T>& operator/=(const default_vec4<T>& v0, T scalar)
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
struct default_mat3
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	default_vec3<T> value[3];

	/*
		Constructors
	*/
	default_mat3() = default;
	default_mat3(T scalar)
	{
		value[0] = scalar;
		value[1] = scalar;
		value[2] = scalar;
	}
	default_mat3(const default_vec3<T>& v0, const default_vec3<T>& v1, const default_vec3<T>& v2)
	{
		value[0] = v0;
		value[1] = v1;
		value[2] = v2;
	}

	/*
		Arithmetic operators
	*/
	constexpr default_mat3 operator+(const default_mat3<T>& other)
	{
		return { value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2] };
	}
	constexpr default_mat3& operator+=(const default_mat3<T>& other)
	{
		value[0] += other.value[0];
		value[1] += other.value[1];
		value[2] += other.value[2];
		return *this;
	}

	constexpr default_mat3 operator-(const default_mat3<T>& other)
	{
		return { value[0] - other.value[0], value[1] - other.value[1], value[2] - other.value[2] };
	}
	constexpr default_mat3& operator-=(const default_mat3<T>& other)
	{
		value[0] -= other.value[0];
		value[1] -= other.value[1];
		value[2] -= other.value[2];
		return *this;
	}

	constexpr default_mat3 operator*(const default_mat3<T>& other)
	{
		return { value[0] * other.value[0], value[1] * other.value[1], value[2] * other.value[2] };
	}
	constexpr default_mat3& operator*=(const default_mat3<T>& other)
	{
		value[0] *= other.value[0];
		value[1] *= other.value[1];
		value[2] *= other.value[2];
		return *this;
	}

	constexpr default_mat3 operator/(const default_mat3<T>& other)
	{
		return { value[0] / other.value[0], value[1] / other.value[1], value[2] / other.value[2] };
	}
	constexpr default_mat3& operator/=(const default_mat3<T>& other)
	{
		value[0] /= other.value[0];
		value[1] /= other.value[1];
		value[2] /= other.value[2];
		return *this;
	}

	/*
		Bracket operators
	*/
	default_vec3<T>& operator[](uint32_t index)
	{
		assert(index >= 0 && index < 3);
		return value[index];
	}

	const default_vec3<T>& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 3);
		return value[index];
	}

};

/*
	mat4 implementation
*/
template<typename T>
struct default_mat4
{
	static_assert(std::is_arithmetic_v<T>, "Templated type T must be an arithmetic type");

	default_vec4<T> value[4];

	/*
		Constructors
	*/
	default_mat4() = default;
	default_mat4(T scalar)
	{
		value[0] = scalar;
		value[1] = scalar;
		value[2] = scalar;
		value[3] = scalar;
	}
	default_mat4(const default_vec4<T>& v0, const default_vec4<T>& v1, const default_vec4<T>& v2, const default_vec4<T>& v3)
	{
		value[0] = v0;
		value[1] = v1;
		value[2] = v2;
		value[3] = v3;
	}

	/*
		Arithmetic operators
	*/
	constexpr default_mat4 operator+(const default_mat4<T>& other)
	{
		return { value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2], value[3] + other.value[3] };
	}
	constexpr default_mat4& operator+=(const default_mat4<T>& other)
	{
		value[0] += other.value[0];
		value[1] += other.value[1];
		value[2] += other.value[2];
		value[3] += other.value[3];
		return *this;
	}

	constexpr default_mat4 operator-(const default_mat4<T>& other)
	{
		return { value[0] - other.value[0], value[1] - other.value[1], value[2] - other.value[2], value[3] - other.value[3] };
	}
	constexpr default_mat4& operator-=(const default_mat4<T>& other)
	{
		value[0] -= other.value[0];
		value[1] -= other.value[1];
		value[2] -= other.value[2];
		value[3] -= other.value[3];
		return *this;
	}

	constexpr default_mat4 operator*(const default_mat4<T>& other)
	{
		return { value[0] * other.value[0], value[1] * other.value[1], value[2] * other.value[2], value[3] * other.value[3] };
	}
	constexpr default_mat4& operator*=(const default_mat4<T>& other)
	{
		value[0] *= other.value[0];
		value[1] *= other.value[1];
		value[2] *= other.value[2];
		value[3] *= other.value[3];
		return *this;
	}

	constexpr default_mat4 operator/(const default_mat4<T>& other)
	{
		return { value[0] / other.value[0], value[1] / other.value[1], value[2] / other.value[2], value[3] / other.value[3] };
	}
	constexpr default_mat4& operator/=(const default_mat4<T>& other)
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
	default_vec4<T>& operator[](uint32_t index)
	{
		assert(index >= 0 && index < 4);
		return value[index];
	}

	const default_vec4<T>& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 4);
		return value[index];
	}

};

template<typename T>
inline constexpr T dot(const default_vec2<T>& v0, const default_vec2<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y;
}

template<typename T>
inline constexpr T dot(const default_vec3<T>& v0, const default_vec3<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

template<typename T>
inline constexpr T dot(const default_vec4<T>& v0, const default_vec4<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
}

template<typename T>
inline constexpr default_vec3<T> cross(const default_vec3<T>& v0, const default_vec3<T>& v1)
{
	return {
		v0.y * v1.z - v0.z * v1.y,
		v0.z * v1.x - v0.x * v1.z,
		v0.x * v1.y - v0.y * v1.x
	};
}

template<typename T>
inline constexpr T length(const default_vec2<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr T length(const default_vec3<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr T length(const default_vec4<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr default_vec2<T> normalize(const default_vec2<T>& v0)
{
	return v0 * (1 / length(v0));
}

template<typename T>
inline constexpr default_vec3<T> normalize(const default_vec3<T>& v0)
{
	return v0 * (1 / length(v0));
}

template<typename T>
inline constexpr default_vec4<T> normalize(const default_vec4<T>& v0)
{
	return v0 * (1 / length(v0));
}

using vec2 = default_vec2<float>;
using vec3 = default_vec3<float>;
using vec4 = default_vec4<float>;
using mat3 = default_mat3<float>;
using mat4 = default_mat4<float>;

}