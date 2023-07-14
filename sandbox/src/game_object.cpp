#include <game_object.hpp>

using namespace anguish::gfx;

GameObject::GameObject(const std::shared_ptr<mesh::Mesh> &mesh, const std::shared_ptr<texture::Texture> &diffuseTexture,
                       const std::shared_ptr<shader::ShaderProgram> &shaderProgram, const glm::vec3 &position,
                       const glm::vec3 &rotation, const glm::vec2 &scale) : Object(mesh, diffuseTexture, shaderProgram),
                                                                            position(position), rotation(rotation),
                                                                            scale(scale) {}

const glm::vec3 &GameObject::getPosition() const {
    return position;
}

const glm::vec3 &GameObject::getRotation() const {
    return rotation;
}

const glm::vec2 &GameObject::getScale() const {
    return scale;
}

void GameObject::setPosition(const glm::vec3 &position) {
    GameObject::position = position;
}

void GameObject::setRotation(const glm::vec3 &rotation) {
    GameObject::rotation = rotation;
}

void GameObject::setScale(const glm::vec2 &scale) {
    GameObject::scale = scale;
}
