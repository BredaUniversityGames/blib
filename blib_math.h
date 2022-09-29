#pragma once
#include <type_traits>

/*

	Todo: Constructors / arithmetic operators / bracket operators

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
struct vec2
{
	static_assert(std::is_scalar_v<T>, "Templated type T must be a scalar type");

	T x = 0, y = 0;

	/*
		Constructors
	*/
	vec2() = default;
	vec2(T scalar)
	{
		x = y = scalar;
	}
	vec2(T _x, T _y)
	{
		x = _x;
		y = _y;
	}

	/*
		Arithmetic operators
	*/
	constexpr vec2 operator+(const vec2& other)
	{
		return { x + other.x, y + other.y };
	}
	constexpr vec2& operator+=(const vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	constexpr vec2 operator-(const vec2& other)
	{
		return { x - other.x, y - other.y };
	}
	constexpr vec2& operator-=(const vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	constexpr vec2 operator*(const vec2& other)
	{
		return { x * other.x, y * other.y };
	}
	constexpr vec2& operator*=(const vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	constexpr vec2 operator/(const vec2& other)
	{
		return { x / other.x, y / other.y };
	}
	constexpr vec2& operator/=(const vec2& other)
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
	Binary arithmetic operators (vec2)
*/
template<typename T>
constexpr vec2<T> operator+(const vec2<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar };
}
template<typename T>
constexpr vec2<T>& operator+=(const vec2<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	return *this;
}

template<typename T>
constexpr vec2<T> operator-(const vec2<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar };
}
template<typename T>
constexpr vec2<T>& operator-=(const vec2<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	return *this;
}

template<typename T>
constexpr vec2<T> operator*(const vec2<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar };
}
template<typename T>
constexpr vec2<T>& operator*=(const vec2<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	return *this;
}

template<typename T>
constexpr vec2<T> operator/(const vec2<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar };
}
template<typename T>
constexpr vec2<T>& operator/=(const vec2<T>& v0, T scalar)
{
	v0.x /= scalar;
	v0.y /= scalar;
	return *this;
}

/*
	vec3 implementation
*/
template<typename T>
struct vec3
{
	static_assert(std::is_scalar_v<T>, "Templated type T must be a scalar type");

	T x = 0, y = 0, z = 0;

	/*
		Constructors
	*/
	vec3() = default;
	vec3(T scalar)
	{
		x = y = z = scalar;
	}
	vec3(T _x, T _y, T _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	/*
		Unary arithmetic operators
	*/
	constexpr vec3 operator+(const vec3& other)
	{
		return { x + other.x, y + other.y, z + other.z };
	}
	constexpr vec3& operator+=(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	constexpr vec3 operator-(const vec3& other)
	{
		return { x - other.x, y - other.y, z - other.z };
	}
	constexpr vec3& operator-=(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	constexpr vec3 operator*(const vec3& other)
	{
		return { x * other.x, y * other.y, z * other.z };
	}
	constexpr vec3& operator*=(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	constexpr vec3 operator/(const vec3& other)
	{
		return { x / other.x, y / other.y, z / other.z };
	}
	constexpr vec3& operator/=(const vec3& other)
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
	Binary arithmetic operators (vec3)
*/
template<typename T>
constexpr vec3<T> operator+(const vec3<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar, v0.z + scalar };
}
template<typename T>
constexpr vec3<T>& operator+=(const vec3<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	v0.z += scalar;
	return *this;
}

template<typename T>
constexpr vec3<T> operator-(const vec3<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar, v0.z - scalar };
}
template<typename T>
constexpr vec3<T>& operator-=(const vec3<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	v0.z -= scalar;
	return *this;
}

template<typename T>
constexpr vec3<T> operator*(const vec3<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar, v0.z * scalar };
}
template<typename T>
constexpr vec3<T>& operator*=(const vec3<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	v0.z *= scalar;
	return *this;
}

template<typename T>
constexpr vec3<T> operator/(const vec3<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar, v0.z / scalar };
}
template<typename T>
constexpr vec3<T>& operator/=(const vec3<T>& v0, T scalar)
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
struct vec4
{
	static_assert(std::is_scalar_v<T>, "Templated type T must be a scalar type");

	T x = 0, y = 0, z = 0, w = 0;

	/*
		Constructors
	*/
	vec4() = default;
	vec4(T scalar)
	{
		x = y = z = w = scalar;
	}
	vec4(T _x, T _y, T _z, T _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	/*
		Arithmetic operators
	*/
	constexpr vec4 operator+(const vec4& other)
	{
		return { x + other.x, y + other.y, z + other.z, w + other.w };
	}
	constexpr vec4& operator+=(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	constexpr vec4 operator-(const vec4& other)
	{
		return { x - other.x, y - other.y, z - other.z, w - other.w };
	}
	constexpr vec4& operator-=(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	constexpr vec4 operator*(const vec4& other)
	{
		return { x * other.x, y * other.y, z * other.z, w * other.w };
	}
	constexpr vec4& operator*=(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	constexpr vec4 operator/(const vec4& other)
	{
		return { x / other.x, y / other.y, z / other.z, w / other.w };
	}
	constexpr vec4& operator/=(const vec4& other)
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
	Binary arithmetic operators (vec4)
*/
template<typename T>
constexpr vec4<T> operator+(const vec4<T>& v0, T scalar)
{
	return { v0.x + scalar, v0.y + scalar, v0.z + scalar, v0.w + scalar };
}
template<typename T>
constexpr vec4<T>& operator+=(const vec4<T>& v0, T scalar)
{
	v0.x += scalar;
	v0.y += scalar;
	v0.z += scalar;
	v0.w += scalar;
	return *this;
}

template<typename T>
constexpr vec4<T> operator-(const vec4<T>& v0, T scalar)
{
	return { v0.x - scalar, v0.y - scalar, v0.z - scalar, v0.w - scalar };
}
template<typename T>
constexpr vec4<T>& operator-=(const vec4<T>& v0, T scalar)
{
	v0.x -= scalar;
	v0.y -= scalar;
	v0.z -= scalar;
	v0.w -= scalar;
	return *this;
}

template<typename T>
constexpr vec4<T> operator*(const vec4<T>& v0, T scalar)
{
	return { v0.x * scalar, v0.y * scalar, v0.z * scalar, v0.w * scalar };
}
template<typename T>
constexpr vec4<T>& operator*=(const vec4<T>& v0, T scalar)
{
	v0.x *= scalar;
	v0.y *= scalar;
	v0.z *= scalar;
	v0.w *= scalar;
	return *this;
}

template<typename T>
constexpr vec4<T> operator/(const vec4<T>& v0, T scalar)
{
	return { v0.x / scalar, v0.y / scalar, v0.z / scalar, v0.w / scalar };
}
template<typename T>
constexpr vec4<T>& operator/=(const vec4<T>& v0, T scalar)
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
struct mat3
{
	static_assert(std::is_scalar_v<T>, "Templated type T must be a scalar type");

	vec3<T> value[3];

	/*
		Constructors
	*/
	mat3() = default;
	mat3(T scalar)
	{
		value[0] = scalar;
		value[1] = scalar;
		value[2] = scalar;
	}
	mat3(const vec3<T>& v0, const vec3<T>& v1, const vec3<T>& v2)
	{
		value[0] = v0;
		value[1] = v1;
		value[2] = v2;
	}

	/*
		Arithmetic operators
	*/
	constexpr mat3 operator+(const mat3<T>& other)
	{
		return { value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2] };
	}
	constexpr mat3& operator+=(const mat3<T>& other)
	{
		value[0] += other.value[0];
		value[1] += other.value[1];
		value[2] += other.value[2];
		return *this;
	}

	constexpr mat3 operator-(const mat3<T>& other)
	{
		return { value[0] - other.value[0], value[1] - other.value[1], value[2] - other.value[2] };
	}
	constexpr mat3& operator-=(const mat3<T>& other)
	{
		value[0] -= other.value[0];
		value[1] -= other.value[1];
		value[2] -= other.value[2];
		return *this;
	}

	constexpr mat3 operator*(const mat3<T>& other)
	{
		return { value[0] * other.value[0], value[1] * other.value[1], value[2] * other.value[2] };
	}
	constexpr mat3& operator*=(const mat3<T>& other)
	{
		value[0] *= other.value[0];
		value[1] *= other.value[1];
		value[2] *= other.value[2];
		return *this;
	}

	constexpr mat3 operator/(const mat3<T>& other)
	{
		return { value[0] / other.value[0], value[1] / other.value[1], value[2] / other.value[2] };
	}
	constexpr mat3& operator/=(const mat3<T>& other)
	{
		value[0] /= other.value[0];
		value[1] /= other.value[1];
		value[2] /= other.value[2];
		return *this;
	}

	/*
		Bracket operators
	*/
	vec3<T>& operator[](uint32_t index)
	{
		assert(index >= 0 && index < 3);
		return value[index];
	}

	const vec3<T>& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 3);
		return value[index];
	}

};

/*
	mat4 implementation
*/
template<typename T>
struct mat4
{
	static_assert(std::is_scalar_v<T>, "Templated type T must be a scalar type");

	vec4<T> value[4];

	/*
		Constructors
	*/
	mat4() = default;
	mat4(T scalar)
	{
		value[0] = scalar;
		value[1] = scalar;
		value[2] = scalar;
		value[3] = scalar;
	}
	mat4(const vec4<T>& v0, const vec4<T>& v1, const vec4<T>& v2, const vec4<T>& v3)
	{
		value[0] = v0;
		value[1] = v1;
		value[2] = v2;
		value[3] = v3;
	}

	/*
		Arithmetic operators
	*/
	constexpr mat4 operator+(const mat4<T>& other)
	{
		return { value[0] + other.value[0], value[1] + other.value[1], value[2] + other.value[2], value[3] + other.value[3] };
	}
	constexpr mat4& operator+=(const mat4<T>& other)
	{
		value[0] += other.value[0];
		value[1] += other.value[1];
		value[2] += other.value[2];
		value[3] += other.value[3];
		return *this;
	}

	constexpr mat4 operator-(const mat4<T>& other)
	{
		return { value[0] - other.value[0], value[1] - other.value[1], value[2] - other.value[2], value[3] - other.value[3] };
	}
	constexpr mat4& operator-=(const mat4<T>& other)
	{
		value[0] -= other.value[0];
		value[1] -= other.value[1];
		value[2] -= other.value[2];
		value[3] -= other.value[3];
		return *this;
	}

	constexpr mat4 operator*(const mat4<T>& other)
	{
		return { value[0] * other.value[0], value[1] * other.value[1], value[2] * other.value[2], value[3] * other.value[3] };
	}
	constexpr mat4& operator*=(const mat4<T>& other)
	{
		value[0] *= other.value[0];
		value[1] *= other.value[1];
		value[2] *= other.value[2];
		value[3] *= other.value[3];
		return *this;
	}

	constexpr mat4 operator/(const mat4<T>& other)
	{
		return { value[0] / other.value[0], value[1] / other.value[1], value[2] / other.value[2], value[3] / other.value[3] };
	}
	constexpr mat4& operator/=(const mat4<T>& other)
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
	vec4<T>& operator[](uint32_t index)
	{
		assert(index >= 0 && index < 4);
		return value[index];
	}

	const vec4<T>& operator[](uint32_t index) const
	{
		assert(index >= 0 && index < 4);
		return value[index];
	}

};

template<typename T>
inline constexpr T dot(const vec2<T>& v0, const vec2<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y;
}

template<typename T>
inline constexpr T dot(const vec3<T>& v0, const vec3<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

template<typename T>
inline constexpr T dot(const vec4<T>& v0, const vec4<T>& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
}

template<typename T>
inline constexpr vec3<T> cross(const vec3<T>& v0, const vec3<T>& v1)
{
	return {
		v0.y * v1.z - v0.z * v1.y,
		v0.z * v1.x - v0.x * v1.z,
		v0.x * v1.y - v0.y * v1.x
	};
}

template<typename T>
inline constexpr T length(const vec2<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr T length(const vec3<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr T length(const vec4<T>& v0)
{
	return std::sqrt(dot(v0, v0));
}

template<typename T>
inline constexpr vec2<T> normalize(const vec2<T>& v0)
{
	return v0 * (1 / length(v0));
}

template<typename T>
inline constexpr vec3<T> normalize(const vec3<T>& v0)
{
	return v0 * (1 / length(v0));
}

template<typename T>
inline constexpr vec4<T> normalize(const vec4<T>& v0)
{
	return v0 * (1 / length(v0));
}

}