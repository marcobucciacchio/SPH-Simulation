#pragma once

#include "Basis.h"

// The Camera class gives us the ability to control a 3D camera in a very simple
// way. The camera sets the GL projection and viewing matrices.

class Camera {
public:
	Camera();

	void Update();
	void Reset();

	// setters
	void SetAspect(float a) 
	{
		Aspect = a;
	}
	void SetDistance(float d)
	{
		Distance = d;
	}
	void SetAzimuth(float az)
	{
		Azimuth = az;
	}
	void SetIncline(float i)
	{
		Incline = i;
	}

	// Accessors
	float GetDistance()
	{
		return Distance;
	}
	float GetAzimuth()
	{
		return Azimuth;
	}
	float GetIncline()
	{
		return Incline;
	}

	const glm::mat4& GetViewProjectMtx()
	{
		return ViewProjectMtx;
	}

private:
	// Perspective Controls
	float FOV;					// FOV (in degrees)
	float Aspect;				// Aspect ratio
	float NearClip;				// near clipping plane dist
	float FarClip;				// far clipping plane dist

	// Polar Controls
	float Distance;				// Dist of the camera eye to the origin
	float Azimuth;				// Rotation around the y-axis of the camera
	float Incline;				// Angle of the camera eye over XZ plane

	// computed data
	glm::mat4 ViewProjectMtx;
};