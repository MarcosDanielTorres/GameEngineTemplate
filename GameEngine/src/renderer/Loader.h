#pragma once
#include "RawModel.h"
#include "GLAD/glad.h"
#include<vector>
#include<iostream>

class Loader{
public:
	RawModel loadToVAO( std::vector<float>& vertices,  std::vector<float>& colors);
	void cleanUp();
private:
	std::vector<unsigned int*> vaos;
	std::vector<unsigned int*> vbos;

	unsigned int createVAO();
	void storeDataInAttributeList(int attributeNumber1, void* data, int size);
	void unbindVAO();

};

