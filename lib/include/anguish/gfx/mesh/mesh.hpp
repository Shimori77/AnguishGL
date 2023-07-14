#pragma once

#include <cstdint>

namespace anguish::gfx::mesh {
    class Mesh {
    private:
        uint32_t vaoID;
        uint32_t indicesVBO;
        uint32_t verticesVBO;
        uint32_t texturesVBO;
        uint32_t indexCount;

    public:
        Mesh(uint32_t vaoID, uint32_t indicesVBO, uint32_t verticesVBO, uint32_t texturesVBO, uint32_t indexCount);
        ~Mesh();

        [[nodiscard]] uint32_t getVaoId() const;
        [[nodiscard]] uint32_t getIndexCount() const;
    };
}