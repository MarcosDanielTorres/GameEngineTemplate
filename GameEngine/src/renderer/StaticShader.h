#pragma once
#include "ShaderProgram.h"

class StaticShader : public ShaderProgram{
public:
	StaticShader(const char* VERTEX_SHADER, const char* FRAGMENT_SHADER);

protected:
    void bindAttributes();
};

