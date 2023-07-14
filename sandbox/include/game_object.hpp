#pragma once

#include <anguish/gfx/object.hpp>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class GameObject : public anguish::gfx::Object {
private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec2 scale;

public:
    GameObject(const std::shared_ptr<anguish::gfx::mesh::Mesh> &mesh, const std::shared_ptr<anguish::gfx::texture::Texture> &diffuseTexture,
               const std::shared_ptr<anguish::gfx::shader::ShaderProgram> &shaderProgram, const glm::vec3 &position,
               const glm::vec3 &rotation, const glm::vec2 &scale);

    [[nodiscard]] const glm::vec3 &getPosition() const;
    [[nodiscard]] const glm::vec3 &getRotation() const;
    [[nodiscard]] const glm::vec2 &getScale() const;

    void setPosition(const glm::vec3 &position);
    void setRotation(const glm::vec3 &rotation);
    void setScale(const glm::vec2 &scale);
};