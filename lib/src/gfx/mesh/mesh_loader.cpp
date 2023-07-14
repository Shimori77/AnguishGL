#include <anguish/gfx/mesh/mesh_loader.hpp>
#include <glad/gl.h>

using namespace anguish::gfx::mesh;

uint32_t bindIndices(const std::vector<uint32_t> &indices);
uint32_t bindArrays(uint8_t index, uint8_t coordSize, const std::vector<float> &data);

std::shared_ptr<Mesh> MeshLoader::load(
        const std::vector<uint32_t> &indices,
        const std::vector<float> &vertices,
        const std::vector<float> &textures) {
    uint32_t vaoID;
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);

    uint32_t indicesVBO = bindIndices(indices);
    uint32_t verticesVBO = bindArrays(0, 2, vertices);
    uint32_t texturesVBO = bindArrays(1, 2, textures);

    glBindVertexArray(0);
    return std::make_shared<Mesh>(vaoID, indicesVBO, verticesVBO, texturesVBO, indices.size());
}

uint32_t bindIndices(const std::vector<uint32_t> &indices) {
    uint32_t vboId;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (long long) (indices.size() * sizeof(uint32_t)), indices.data(), GL_STATIC_DRAW);

    return vboId;
}

uint32_t bindArrays(uint8_t index, uint8_t coordSize, const std::vector<float> &data) {
    uint32_t vboId;
    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, (long long) (data.size() * sizeof(uint32_t)), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(index, coordSize, GL_FLOAT, false, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    return vboId;
}