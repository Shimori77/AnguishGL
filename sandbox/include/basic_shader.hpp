#pragma once
#include <anguish/gfx/shader/shader_program.hpp>
#include <anguish/gfx/shader/shader_loader.hpp>


class BasicShader : public anguish::gfx::shader::ShaderProgram {
public:
    BasicShader(uint32_t shaderProgramId, const std::shared_ptr<anguish::gfx::shader::Shader> &vertexShader,
                const std::shared_ptr<anguish::gfx::shader::Shader> &fragmentShader);
};

class BasicShaderLoader : public anguish::gfx::shader::ShaderLoader<BasicShader> {
public:
    std::shared_ptr<BasicShader>
    loadShaderProgram(const std::string &vertexShaderSourcePath, const std::string &fragmentShaderSourcePath) override;

    std::shared_ptr<anguish::gfx::shader::Shader>
    compileShader(const std::string &shaderSourcePath, uint32_t shaderType) override;
};
