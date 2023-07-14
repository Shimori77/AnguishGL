#include <anguish/gfx/texture/texture.hpp>

#include <glad/gl.h>

anguish::gfx::texture::Texture::Texture(uint32_t textureID, uint16_t width, uint16_t height) {
    this->textureID = textureID;
    this->width = width;
    this->height = height;
}

anguish::gfx::texture::Texture::~Texture() {
    glDeleteTextures(1, &this->textureID);
}

uint32_t anguish::gfx::texture::Texture::getTextureId() const {
    return textureID;
}

uint16_t anguish::gfx::texture::Texture::getWidth() const {
    return width;
}

uint16_t anguish::gfx::texture::Texture::getHeight() const {
    return height;
}
