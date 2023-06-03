#include "Camera.h"
#include <glm/gtx/euler_angles.hpp>


Camera::Camera()
{
	Reset();
}

void Camera::Update()
{
	// compute camera world matrix
	glm::mat4 world(1);
	world[3][2] = Distance;
	world = glm::eulerAngleY(glm::radians(-Azimuth)) * glm::eulerAngleX(glm::radians(-Incline)) * world;

	// View Matrix (inverse of world matrix)
	glm::mat4 view = glm::inverse(world);

	// perspective projection matrix
	glm::mat4 project = glm::perspective(glm::radians(FOV), Aspect, NearClip, FarClip);

	// Final view-projection matrix
	ViewProjectMtx = project * view;
}


void Camera::Reset() 
{
	FOV = 45.0f;
	Aspect = 1.33f;
	NearClip = 0.1f;
	FarClip = 100.0f;

	Distance = 10.0f;
	Azimuth = 0.0f;
	Incline = 20.0f;

}