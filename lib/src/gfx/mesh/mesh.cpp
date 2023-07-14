#include <anguish/gfx/mesh/mesh.hpp>

#include <glad/gl.h>

anguish::gfx::mesh::Mesh::Mesh(uint32_t vaoID, uint32_t indicesVBO, uint32_t verticesVBO, uint32_t texturesVBO,
                               uint32_t indexCount) {
    this->vaoID = vaoID;
    this->indicesVBO = indicesVBO;
    this->verticesVBO = verticesVBO;
    this->texturesVBO = texturesVBO;
    this->indexCount = indexCount;
}

anguish::gfx::mesh::Mesh::~Mesh() {
    glDeleteBuffers(1, &this->indicesVBO);
    glDeleteBuffers(1, &this->verticesVBO);
    glDeleteBuffers(1, &this->texturesVBO);

    glDeleteVertexArrays(1, &this->vaoID);
}

uint32_t anguish::gfx::mesh::Mesh::getVaoId() const {
    return this->vaoID;
}

uint32_t anguish::gfx::mesh::Mesh::getIndexCount() const {
    return this->indexCount;
}
