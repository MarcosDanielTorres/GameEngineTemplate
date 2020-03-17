#include "StaticShader.h"

void StaticShader::bindAttributes() {
	StaticShader::bindAttribute(0, "position");
	StaticShader::bindAttribute(1, "color");
	linkProgram();
}

StaticShader::StaticShader(const char* VERTEX_SHADER, const char* FRAGMENT_SHADER) : ShaderProgram(VERTEX_SHADER, FRAGMENT_SHADER) {
	bindAttributes();
}

