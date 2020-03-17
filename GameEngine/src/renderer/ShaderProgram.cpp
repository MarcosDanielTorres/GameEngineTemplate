#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath) : 
	programID{ glCreateProgram() },
	vertexShaderID{ loadShader(vertexPath, GL_VERTEX_SHADER) },
	fragmentShaderID{ loadShader(fragmentPath, GL_FRAGMENT_SHADER) }{
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
}


unsigned int ShaderProgram::loadShader(const char* path, unsigned int type) {
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::ifstream vShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open file
        vShaderFile.open(path);
        std::stringstream vShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        // close file handler
        vShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    unsigned int id = glCreateShader(type);
    const char* message = &vertexCode[0];
    
	glShaderSource(id, 1, &message, nullptr);
	glCompileShader(id);

	// Error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!\n";
		std::cout << message << std::endl;
		return 0;
	}

    return id;
}

void ShaderProgram::start() {
	glUseProgram(programID);
}

void ShaderProgram::stop() {
	glUseProgram(0);
}

void ShaderProgram::cleanUp() {
	stop();
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	glDeleteProgram(programID);
}

void ShaderProgram::bindAttribute(int attribute, const char* variableName) {
	glBindAttribLocation(programID, attribute, variableName);
}

void ShaderProgram::linkProgram() {
	glLinkProgram(programID);
	glValidateProgram(programID);
}
