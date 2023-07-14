#pragma once

#include <string>
#include <cstdint>

namespace anguish::gfx::shader {
    class Shader {
    private:
        uint32_t shaderId;
        uint32_t shaderType;
        std::string shaderSourcePath;

    public:
        Shader(uint32_t shaderId, uint32_t shaderType, std::string shaderSourcePath);
        virtual ~Shader();

        [[nodiscard]] uint32_t getShaderId() const;
        [[nodiscard]] uint32_t getShaderType() const;
        [[nodiscard]] const std::string &getShaderSourcePath() const;
    };
}