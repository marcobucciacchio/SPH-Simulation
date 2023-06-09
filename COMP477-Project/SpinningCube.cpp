#include "SpinningCube.h"


SpinningCube::SpinningCube() {
	// Initialize constant data
	Position = glm::vec3(0);
	Axis = glm::vec3(0, 1, 0);		// Y-Axis
	CubeModel.MakeBox(glm::vec3(-1), glm::vec3(1));
	SpinDelta = 0.0001f;

	// Resets variable data
	Reset();
}

void SpinningCube::Update() {
	// Update (animate) any variable properties
	Angle += SpinDelta;
	WorldMtx = glm::rotate(Angle, Axis);
	WorldMtx[3] = glm::vec4(Position, 1);
}

void SpinningCube::Reset() {
	// Reset dynamic variables to a default state
	Angle = 0;
	WorldMtx = glm::mat4(1);		// Reset to identity matrix
}

void SpinningCube::Draw(const glm::mat4& viewProjMtx, uint shader) {
	CubeModel.Draw(WorldMtx, viewProjMtx, shader);
}

