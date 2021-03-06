#pragma once

#include <string>
#include <map>

#include <GL/glew.h>

#include "Material.h"
#include "Light.h"

#include "../../../math/math.h"
#include "../../../utils/fileutils.h"
#include "../../../utils/glcall.h"

class Shader
{
public:
	Shader();
	Shader(std::string vertPath, std::string fragmPath);
	~Shader();

	void compile(std::string& errorMessage);

	void enable() const;
	void disable() const;

	GLuint getId() const;
	bool isOk() const;

	GLint getUniformLocation(const GLchar* name);

	void setUniform(const GLchar* name, float value);
	void setUniform(const GLchar* name, int value);
	void setUniform(const GLchar* name, const vec2& vector);
	void setUniform(const GLchar* name, const vec3& vector);
	void setUniform(const GLchar* name, const vec4& vector);
	void setUniform(const GLchar* name, const mat4& matrix);
	void setUniform(const std::string& name, const Material& material);
	void setUniform(const std::string& name, const Light& light);

private:
	GLuint shader_ = 0;
	std::map< std::string, GLint > uniformsCache_;
	std::string vertPath_;
	std::string fragPath_;

private:
	GLuint load(std::string & errorMessage);
	static bool compileShader(GLuint shader, const char* code, std::string& errorMessage, const std::string& errorPrefix = "[Shader] Compile error | ");
	static bool linkProgram(GLuint program, GLuint vertex, GLuint fragment, std::string& errorMessage, const std::string& errorPrefix = "[Shader program] Compile error | ");
	static std::string getShaderErrorMessage(GLuint shader);
	static std::string getProgramErrorMessage(GLuint program);
};
