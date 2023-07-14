#include <anguish/gfx/shader/shader.hpp>

#include <glad/gl.h>
#include <utility>

using namespace anguish::gfx::shader;

Shader::Shader(uint32_t shaderId, uint32_t shaderType, std::string shaderSourcePath) {
    this->shaderId = shaderId;
    this->shaderType = shaderType;
    this->shaderSourcePath = std::move(shaderSourcePath);
}

Shader::~Shader() {
    glDeleteShader(this->shaderId);
}

uint32_t Shader::getShaderId() const {
    return shaderId;
}

uint32_t Shader::getShaderType() const {
    return shaderType;
}

const std::string &Shader::getShaderSourcePath() const {
    return shaderSourcePath;
}
