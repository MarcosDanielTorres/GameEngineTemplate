#include "RawModel.h"

RawModel::RawModel(unsigned int vaoID, int vertexCount) 
	: vaoID{ vaoID }, vertexCount{ vertexCount } {
	std::cout << "Raw Model created with " << vaoID << " and " << "vertexCount of " << vertexCount << std::endl;
}

unsigned int RawModel::getVaoID() { return vaoID; }
int RawModel::getVertexCount(){ return vertexCount; }
