#pragma once
#include <anguish/gfx/shader/shader.hpp>
#include <anguish/gfx/shader/shader_program.hpp>

namespace anguish::gfx::shader {
    template<class T>
    class ShaderLoader {
    public:
        virtual std::shared_ptr<T> loadShaderProgram(
                const std::string &vertexShaderSourcePath,
                const std::string &fragmentShaderSourcePath
        ) = 0;

        virtual std::shared_ptr<Shader> compileShader(const std::string &shaderSourcePath, uint32_t shaderType) = 0;
    };
}
