#include <basic_shader.hpp>

#include <glad/gl.h>

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

using namespace anguish::gfx::shader;

std::shared_ptr<BasicShader> BasicShaderLoader::loadShaderProgram(const std::string &vertexShaderSourcePath,
                                                                  const std::string &fragmentShaderSourcePath) {

    std::shared_ptr<Shader> vertexShader = compileShader(vertexShaderSourcePath, GL_VERTEX_SHADER);
    std::shared_ptr<Shader> fragmentShader = compileShader(fragmentShaderSourcePath, GL_FRAGMENT_SHADER);

    uint32_t shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, vertexShader->getShaderId());
    glAttachShader(shaderProgramId, fragmentShader->getShaderId());
    glLinkProgram(shaderProgramId);
    glValidateProgram(shaderProgramId);

    return std::make_shared<BasicShader>(shaderProgramId, std::move(vertexShader), std::move(fragmentShader));
}

std::shared_ptr<Shader> BasicShaderLoader::compileShader(const std::string &shaderSourcePath, uint32_t shaderType) {
    std::string shaderSource;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        std::stringstream sourceCodeStream;
        shaderFile.open(shaderSourcePath);
        sourceCodeStream << shaderFile.rdbuf();

        shaderFile.close();
        shaderSource = sourceCodeStream.str();
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    const char *sourceStr = shaderSource.c_str();

    uint32_t shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &sourceStr, nullptr);
    glCompileShader(shaderId);

    return std::make_shared<Shader>(shaderId, shaderType, shaderSourcePath);
}

BasicShader::BasicShader(uint32_t shaderProgramId, const std::shared_ptr<Shader> &vertexShader, const std::shared_ptr<Shader> &fragmentShader) : ShaderProgram(shaderProgramId, vertexShader, fragmentShader) {}
