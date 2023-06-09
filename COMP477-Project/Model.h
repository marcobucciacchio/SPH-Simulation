#pragma once
#include "Basis.h"

struct ModelVertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
};


class Model
{
public:
	Model();
	~Model();

	void Draw(const glm::mat4& modelMtx, const glm::mat4& viewProjMtx, uint shader);

	void MakeBox(const glm::vec3& boxMin, const glm::vec3& boxMax);
	void SetBuffers(const std::vector<ModelVertex>& vtx, const std::vector<uint>& idx);

	// Access functions

private:
	uint VertexBuffer;
	uint IndexBuffer;

	int Count;
};