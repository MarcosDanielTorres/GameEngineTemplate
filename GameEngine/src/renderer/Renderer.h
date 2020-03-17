#pragma once
#include<GLAD/glad.h>
#include "RawModel.h"
#include<iostream>

class Renderer{
public:
	void prepare();

	void render(RawModel model, int attributeNumber, int attributeNumber2);
};

