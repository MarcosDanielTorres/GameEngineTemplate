#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<GLAD/glad.h>

class ShaderProgram{
private:
	unsigned int programID;
	unsigned int vertexShaderID;
	unsigned int fragmentShaderID;

	static unsigned int loadShader(const char* path, unsigned int type);

public:
	ShaderProgram(const char* vertexFile, const char* fragmentFile);

	unsigned int getProgramID() { return programID; }
	
	void start();

	void stop();

	void cleanUp();

	void bindAttribute(int attribute, const char* variableName);

protected:
	virtual void bindAttributes() = 0;
	void linkProgram();

};

