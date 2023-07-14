#pragma once

#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

namespace anguish::core {
    class Math {
    public:
        static glm::mat4 calculateOrthoProjectionMatrix(uint32_t width, uint32_t height, float nearPlane, float farPlane);
        static glm::mat4 calculateModelMatrix(glm::vec3 position, glm::vec3 rotation, glm::vec2 scale);
        static glm::mat4 calculateViewMatrix(glm::vec2 position, glm::vec2 at, glm::vec2 panning);
    };
}