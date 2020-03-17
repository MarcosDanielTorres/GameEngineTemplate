#include "Loader.h"

RawModel Loader::loadToVAO(std::vector<float>& data, std::vector<float>& colors) {
	unsigned int vaoID = createVAO();
	storeDataInAttributeList(0, &data[0], data.size() * sizeof(float));
	if(!colors.empty())
		storeDataInAttributeList(1, &colors[0], colors.size() * sizeof(float));
	unbindVAO();
	RawModel model(vaoID, 3);
	return model; 
}

unsigned int Loader::createVAO() {
	unsigned int vaoID;
	glGenVertexArrays(1, &vaoID);
	vaos.push_back(&vaoID);
	glBindVertexArray(vaoID);
	return vaoID;
}

void Loader::storeDataInAttributeList(int attributeNumber1, void* data, int size) {
	unsigned int vboID;
	glGenBuffers(1, &vboID);
	vbos.push_back(&vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(attributeNumber1);
	glVertexAttribPointer(attributeNumber1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVAO() {
	glBindVertexArray(0);
}

void Loader::cleanUp() {
	for (unsigned int* vao : vaos) {
		glDeleteVertexArrays(0, vao);
	}

	for (unsigned int* vbo : vbos) {
		glDeleteBuffers(0, vbo);
	}
}
