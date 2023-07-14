#include <anguish/gfx/shader/shader_program.hpp>
#include <glad/gl.h>

#include <utility>

using namespace anguish::gfx::shader;

ShaderProgram::ShaderProgram(uint32_t shaderProgramId, std::shared_ptr<Shader> vertexShader,
                             std::shared_ptr<Shader> fragmentShader) {
    this->shaderProgramId = shaderProgramId;
    this->vertexShader = std::move(vertexShader);
    this->fragmentShader = std::move(fragmentShader);
}

ShaderProgram::~ShaderProgram() {
    glDetachShader(this->shaderProgramId, vertexShader->getShaderId());
    glDetachShader(this->shaderProgramId, fragmentShader->getShaderId());

    glDeleteProgram(this->shaderProgramId);
}

void ShaderProgram::start() {
    glUseProgram(this->shaderProgramId);
}

void ShaderProgram::stop() {
    glUseProgram(0);
}

uint32_t ShaderProgram::getShaderProgramId() const {
    return shaderProgramId;
}

const std::shared_ptr<Shader> &ShaderProgram::getVertexShader() const {
    return vertexShader;
}

const std::shared_ptr<Shader> &ShaderProgram::getFragmentShader() const {
    return fragmentShader;
}

int32_t ShaderProgram::getUniformLocation(const std::string &name) const {
    return glGetUniformLocation(this->shaderProgramId, name.c_str());
}

void ShaderProgram::setUniform(int32_t uniform, bool value) {
    glUniform1i(uniform, value);
}

void ShaderProgram::setUniform(int32_t uniform, int32_t value) {
    glUniform1i(uniform, value);
}

void ShaderProgram::setUniform(int32_t uniform, float value) {
    glUniform1f(uniform, value);
}

void ShaderProgram::setUniform(int32_t uniform, const glm::mat4 &matrix) {
    glUniformMatrix4fv(uniform, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::setUniform(int32_t uniform, const glm::mat3 &matrix) {
    glUniformMatrix3fv(uniform, 1, GL_FALSE, glm::value_ptr(matrix));
}
