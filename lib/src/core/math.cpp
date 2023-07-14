#include <anguish/core/math.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

using namespace anguish::core;

glm::mat4 Math::calculateOrthoProjectionMatrix(uint32_t width, uint32_t height, float nearPlane, float farPlane) {
    return glm::ortho(0.f, (float) width, (float) height, 0.f, nearPlane, farPlane);
}

glm::mat4 Math::calculateModelMatrix(glm::vec3 position, glm::vec3 rotation, glm::vec2 scale) {
    glm::mat4 modelMatrix(1.0f);

    position.x = -position.x;

    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(scale, 0));

    return modelMatrix;
}

glm::mat4 Math::calculateViewMatrix(glm::vec2 position, glm::vec2 at, glm::vec2 panning) {
    return glm::lookAt(
            glm::vec3(position.x, position.y, -1.f),
            glm::vec3(at.x, at.y, 0.f),
            glm::vec3(panning.x, panning.y, 0.f)
    );
}
