#pragma once
#include <anguish/gfx/texture/texture.hpp>

#include <memory>
#include <string>

namespace anguish::gfx::texture {
    class TextureLoader {
    public:
        virtual std::shared_ptr<Texture> loadTexture2D(const std::string &texturePath);
        virtual void setParametersTexture2D(uint32_t textureID);
    };
}