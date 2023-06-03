#pragma once
#include <vector>
#include "GL/glew.h"
#include <glm/glm.hpp>
#include "Particle.h"
#include "Geometry.h"
#define TABLE_SIZE 1000000

class SPHSystem
{
private:
	//particle data
	unsigned int numParticles;
	std::vector<Particle*> particles;
	std::vector<std::vector<Particle*>> neighbouringParticles;
	bool started;

	//kernel/fluid constants
	float DENSITY_KERN, PRESSURE_GRAD, VISC_KERN, GAS_CONSTANT, MASS, H2, SELF_DENS;

	//fluid properties
	float restDensity;
	float viscosity, h, g, tension, boxWidth;

	//initializes the particles that will be used
	void initParticles();

	// Creates hash table for particles in infinite domain
	Particle** particleTable;
	void buildTable();
	uint getHash(glm::ivec3 cell);
	glm::ivec3 getCell(Particle* p);

	// Updates position of all particles
	// SPH should handle this instead of the particle class
	void updateParticles(float deltaTime);

	// Sphere geometry for rendering
	Geometry* sphere;
	glm::mat4 sphereScale;
	glm::mat4* sphereModelMtxs;
	GLuint vbo;

public:
	SPHSystem(unsigned int numParticles, float mass, float restDensity, float gasConst, float viscosity, float h, float g, float tension, float boxWidth);
	~SPHSystem();

	//updates the SPH system
	void update(float deltaTime);

	//draws the SPH system & its particles
	void draw(glm::mat4 viewProjMtx, GLuint shader);

	void print();

	void reset();
	void startSimulation();
};

