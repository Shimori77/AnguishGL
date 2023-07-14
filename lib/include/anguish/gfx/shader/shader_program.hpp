#pragma once
#include <anguish/gfx/shader/shader.hpp>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <memory>

namespace anguish::gfx::shader {
    class ShaderProgram {
    private:
        uint32_t shaderProgramId;
        std::shared_ptr<Shader> vertexShader;
        std::shared_ptr<Shader> fragmentShader;

    public:
        ShaderProgram(
                uint32_t shaderProgramId,
                std::shared_ptr<Shader> vertexShader,
                std::shared_ptr<Shader> fragmentShader
        );

        virtual ~ShaderProgram();

        virtual void start();
        virtual void stop();

        int32_t getUniformLocation(const std::string &name) const;

        static void setUniform(int32_t uniform, bool value);
        static void setUniform(int32_t uniform, int32_t value);
        static void setUniform(int32_t uniform, float value);

        static void setUniform(int32_t uniform, const glm::mat4 &matrix);
        static void setUniform(int32_t uniform, const glm::mat3 &matrix);

        [[nodiscard]] uint32_t getShaderProgramId() const;
        [[nodiscard]] const std::shared_ptr<Shader> &getVertexShader() const;
        [[nodiscard]] const std::shared_ptr<Shader> &getFragmentShader() const;
    };
}