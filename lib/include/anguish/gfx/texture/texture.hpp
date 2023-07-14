#pragma once

#include <cstdint>

namespace anguish::gfx::texture {
    class Texture {
    private:
        uint32_t textureID;
        uint16_t width, height;

    public:
        Texture(uint32_t textureID, uint16_t width, uint16_t height);
        ~Texture();

        [[nodiscard]] uint32_t getTextureId() const;
        [[nodiscard]] uint16_t getWidth() const;
        [[nodiscard]] uint16_t getHeight() const;
    };
}