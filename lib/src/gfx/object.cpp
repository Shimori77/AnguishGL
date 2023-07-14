#include <anguish/gfx/object.hpp>

using namespace anguish::gfx;

const std::shared_ptr<mesh::Mesh> &Object::getMesh() const {
    return mesh;
}

const std::shared_ptr<texture::Texture> &Object::getDiffuseTexture() const {
    return diffuseTexture;
}

const std::shared_ptr<shader::ShaderProgram> &Object::getShaderProgram() const {
    return shaderProgram;
}

Object::Object(std::shared_ptr<mesh::Mesh> mesh, std::shared_ptr<texture::Texture> diffuseTexture,
               std::shared_ptr<shader::ShaderProgram> shaderProgram) {
    this->mesh = std::move(mesh);
    this->diffuseTexture = std::move(diffuseTexture);
    this->shaderProgram = std::move(shaderProgram);
}


