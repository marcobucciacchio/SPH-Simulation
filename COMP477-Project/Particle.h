#pragma once
#include "GL/glew.h"
#include <glm/glm.hpp>
#include "Model.h"


class Particle
{
private:
	static int pCount;
public:
	//attributes
	float mass, size, elasticity;
	glm::vec3 position, velocity, acceleration;
	glm::vec3 force;

	//for linked list
	Particle* next;

	float density;
	float pressure;
	float id;

	Particle(float mass, float size, glm::vec3 position, glm::vec3 velocity);
	~Particle();
};