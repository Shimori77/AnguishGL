#include <anguish/gfx/texture/texture_loader.hpp>

#include <glad/gl.h>

#define STB_IMAGE_IMPLEMENTATION 1
#include <stb/stb_image.h>

#include <iostream>
#include <stdexcept>

using namespace anguish::gfx::texture;

std::shared_ptr<Texture> TextureLoader::loadTexture2D(const std::string &texturePath) {
    uint32_t textureID;
    int32_t width, height, channels;

    //stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    if (!data) {
        std::cerr << "Unable to load a texture: " << texturePath << "!" << std::endl;
        throw std::invalid_argument("Error while loading texture!");
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    this->setParametersTexture2D(textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    return std::make_shared<Texture>(textureID, width, height);
}

void TextureLoader::setParametersTexture2D(uint32_t textureID) {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
