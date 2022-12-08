#pragma once
#include "../Math/MathUtils.h"
#include "../Math/Ray.h"

class Camera
{
public:
	Camera(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up, float fov, float aspectRatio);
	void LookAt(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up);
	Ray PointToRay(const glm::vec2& point) const;

private:
	void CalculateViewPlane();

private:
	//eye position
	glm::vec3 m_eye{ 0 };

	// camera axis
	glm::vec3 m_right{ 0 };
	glm::vec3 m_up{ 0 };
	glm::vec3 m_forward{ 0 };

	// view plane origin and axis
	glm::vec3 m_lowerLeft{ 0 };
	glm::vec3 m_horizontal{ 0 };
	glm::vec3 m_vertical{ 0 };

	float m_fov{ 0 };
	float m_aspectRatio{ 0 };

};