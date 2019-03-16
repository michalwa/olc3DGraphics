#include "3dmath.h"

vec3f vec3f::operator +   (const vec3f& other) { return { x + other.x,  y + other.y,  z + other.z   }; }
vec3f vec3f::operator -   (const vec3f& other) { return { x - other.x,  y - other.y,  z - other.z   }; }
vec3f vec3f::operator *   (const float scalar) { return { x * scalar,   y * scalar,   z * scalar    }; }
vec3f vec3f::operator /   (const float scalar) { return { x / scalar,   y / scalar,   z / scalar    }; }
vec3f& vec3f::operator += (const vec3f& other)          { x += other.x; y += other.y; z += other.z; return *this; }
vec3f& vec3f::operator -= (const vec3f& other)          { x -= other.x; y -= other.y; z -= other.z; return *this; }
vec3f& vec3f::operator *= (const float scalar)          { x *= scalar;  y *= scalar;  z *= scalar;  return *this; }
vec3f& vec3f::operator /= (const float scalar)          { x /= scalar;  y /= scalar;  z /= scalar;  return *this; }

float& vec3f::operator [] (std::size_t i)
{
	return *((float*)this + i);
}


vec4f vec4f::operator +   (const vec4f& other) { return { x + other.x,  y + other.y,  z + other.z,  w + other.w   }; }
vec4f vec4f::operator -   (const vec4f& other) { return { x - other.x,  y - other.y,  z - other.z,  w - other.w   }; }
vec4f vec4f::operator *   (const float scalar) { return { x * scalar,   y * scalar,   z * scalar,   w * scalar    }; }
vec4f vec4f::operator /   (const float scalar) { return { x / scalar,   y / scalar,   z / scalar,   w / scalar    }; }
vec4f& vec4f::operator += (const vec4f& other)          { x += other.x; y += other.y; z += other.z; w += other.w; return *this; }
vec4f& vec4f::operator -= (const vec4f& other)          { x -= other.x; y -= other.y; z -= other.z; w -= other.w; return *this; }
vec4f& vec4f::operator *= (const float scalar)          { x *= scalar;  y *= scalar;  z *= scalar;  w *= scalar;  return *this; }
vec4f& vec4f::operator /= (const float scalar)          { x /= scalar;  y /= scalar;  z /= scalar;  w /= scalar;  return *this; }

float& vec4f::operator [] (std::size_t i)
{
	return *((float*)this + i);
}


vec4f mat4f::operator * (const vec4f& v)
{
	vec4f o = { 0 };
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			o[i] += ((vec4f)v)[j] * m[j][i];
		}
	}
	return o;
}

vec3f mat4f::operator * (const vec3f& i)
{
	vec4f o4 = *this * vec4f({ i.x, i.y, i.z, 1 });

	vec3f o;
	o.x = o4.x;
	o.y = o4.y;
	o.z = o4.z;

	if(o4.w != 0) o /= o4.w;

	return o;
}


vec3f& tri3f::operator [] (int index)
{
	return vert[index];
}


mat4f CreateRotationMatrix(AXIS axis, float theta)
{
	mat4f mat;
	mat.m[3][3] = 1.0f;

	switch(axis) {
	case AXIS_X:
		mat.m[0][0] = 1.0f;
		mat.m[1][1] = cosf(theta);
		mat.m[1][2] = sinf(theta);
		mat.m[2][1] = -sinf(theta);
		mat.m[2][2] = cosf(theta);
		break;
	case AXIS_Y:
		mat.m[0][0] = cosf(theta);
		mat.m[2][0] = sinf(theta);
		mat.m[1][1] = 1.0f;
		mat.m[0][2] = -sinf(theta);
		mat.m[2][2] = cosf(theta);
		break;
	case AXIS_Z:
		mat.m[0][0] = cosf(theta);
		mat.m[0][1] = sinf(theta);
		mat.m[1][0] = -sinf(theta);
		mat.m[1][1] = cosf(theta);
		mat.m[2][2] = 1.0f;
		break;
	}

	return mat;
}
