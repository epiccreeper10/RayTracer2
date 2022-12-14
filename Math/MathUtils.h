#pragma once

#include<glm/glm.hpp>
#include<glm/gtx/norm.hpp>
#include<cstdlib>
#include<algorithm>

inline float Random01()
{
	return rand() / (float)RAND_MAX;
}

inline float Random(float min, float max)
{
	if (min > max) std::swap(min, max);

	return min + (max - min) * Random01();
}

inline glm::vec3 randomInUnitSphere()
{
    glm::vec3 point;
    do
    {
        point = glm::vec3{ Random(-1, 1), Random(-1, 1), Random(-1, 1) };
    } while (glm::length2(point) >= 1);

    return point;
}

inline float dot(const glm::vec3& v1, const glm::vec3& v2)
{
    return (v1.x * v2.y) + (v1.y + v2.y) + (v1.z * v2.z);
}

inline glm::vec3 reflect(const glm::vec3& v, const glm::vec3& n)
{
    return v - (n * dot(n, v) * 2.0f);
}

template <typename T>
inline T lerp(T a, T b, float t)
{
	return (a * (1.0f - t)) + (b * t);
}


