#pragma once
#include<iostream>
class RawModel{
private:
	unsigned int vaoID;
	int vertexCount;

public:
	RawModel(unsigned int vaoID, int vertexCount);

	unsigned int getVaoID();
	int getVertexCount();
};

