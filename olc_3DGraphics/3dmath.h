#pragma once
#include <cstddef>
#include <vector>

// Floating point approximation of PI
#define PI 3.1415927f

// 3d vector
struct vec3f
{
	float x, y, z;

	vec3f operator + (const vec3f& other);
	vec3f operator - (const vec3f& other);
	vec3f operator * (const float scalar);
	vec3f operator / (const float scalar);
	vec3f& operator += (const vec3f& other);
	vec3f& operator -= (const vec3f& other);
	vec3f& operator *= (const float scalar);
	vec3f& operator /= (const float scalar);

	// The i-th coordinate of this vector
	float& operator [] (std::size_t i);
};

// 4d vector
struct vec4f
{
	float x, y, z, w;

	vec4f operator + (const vec4f& other);
	vec4f operator - (const vec4f& other);
	vec4f operator * (const float scalar);
	vec4f operator / (const float scalar);
	vec4f& operator += (const vec4f& other);
	vec4f& operator -= (const vec4f& other);
	vec4f& operator *= (const float scalar);
	vec4f& operator /= (const float scalar);

	// The i-th coordinate of this vector
	float& operator [] (std::size_t i);
};

// 4x4 matrix
struct mat4f
{
	float m[4][4] = { 0 };

	// Multiples this 4x4 matrix by a 4d vector
	vec4f operator * (const vec4f& v);

	// Multiplies this 4x4 matrix and a 3d vector.
	// The output w component is used to divide the x, y and z components
	// of the output vector, if w != 0
	vec3f operator * (const vec3f& i);
};

// 3d triangle
struct tri3f
{
	// Vertices
	vec3f vert[3];

	// The i-th vertex of this triangle
	vec3f& operator [] (int index);
};

// 3d mesh
struct mesh3f
{
	// Triangles
	std::vector<tri3f> tris;
};

enum AXIS
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

// Creates a 4x4 3d rotation matrix that will perform rotation along the specified
// axis with the specified angle upon multiplication
mat4f CreateRotationMatrix(AXIS axis, float theta);
