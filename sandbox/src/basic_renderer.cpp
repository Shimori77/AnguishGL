#include <basic_renderer.hpp>

#include <glad/gl.h>
#include <algorithm>
#include <chrono>

#include <anguish/core/math.hpp>

BasicRenderer::BasicRenderer() {
    using namespace anguish::core;

    this->projectionMatrix = Math::calculateOrthoProjectionMatrix(1366, 768, 0.1f, 100.f);
    this->viewMatrix = Math::calculateViewMatrix(glm::vec2 {}, glm::vec2 {}, glm::vec2 {0, 1});
}

void BasicRenderer::renderAll() {
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::duration<float, std::milli> duration;

    static clock::time_point start = clock::now();

    std::for_each(this->getRenderList().begin(), this->getRenderList().end(), [this](const std::shared_ptr<GameObject>& obj) {
        obj->getShaderProgram()->start();

        glm::mat4 modelMatrix = anguish::core::Math::calculateModelMatrix(obj->getPosition(), obj->getRotation(), obj->getScale());
        glm::mat4 mvp = this->projectionMatrix * this->viewMatrix * modelMatrix;

        int32_t mvpUniformId = obj->getShaderProgram()->getUniformLocation("mvp");
        anguish::gfx::shader::ShaderProgram::setUniform(mvpUniformId, mvp);

        int32_t timeUniformId = obj->getShaderProgram()->getUniformLocation("iTime");
        duration elapsed = clock::now() - start;

        anguish::gfx::shader::ShaderProgram::setUniform(timeUniformId, elapsed.count() / 1000.f);

        glBindVertexArray(obj->getMesh()->getVaoId());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glBindTextureUnit(0, obj->getDiffuseTexture()->getTextureId());

        glDrawElements(GL_TRIANGLES, (int) obj->getMesh()->getIndexCount(), GL_UNSIGNED_INT, nullptr);

        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
        obj->getShaderProgram()->stop();
    });
}

void BasicRenderer::addToRenderList(std::shared_ptr<GameObject> obj) {
    this->getRenderList().push_back(obj);
}

