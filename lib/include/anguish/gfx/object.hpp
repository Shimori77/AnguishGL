#pragma once

#include <anguish/gfx/mesh/mesh.hpp>
#include <anguish/gfx/texture/texture.hpp>
#include <anguish/gfx/shader/shader_program.hpp>

#include <memory>

namespace anguish::gfx {
    class Object {
    private:
        std::shared_ptr<mesh::Mesh> mesh;
        std::shared_ptr<texture::Texture> diffuseTexture;
        std::shared_ptr<shader::ShaderProgram> shaderProgram;

    public:
        Object(std::shared_ptr<mesh::Mesh> mesh, std::shared_ptr<texture::Texture> diffuseTexture, std::shared_ptr<shader::ShaderProgram> shaderProgram);

        [[nodiscard]] const std::shared_ptr<mesh::Mesh> &getMesh() const;
        [[nodiscard]] const std::shared_ptr<texture::Texture> &getDiffuseTexture() const;
        [[nodiscard]] const std::shared_ptr<shader::ShaderProgram> &getShaderProgram() const;
    };
}