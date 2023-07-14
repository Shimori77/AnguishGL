#pragma once

#include <anguish/gfx/renderer.hpp>
#include <glm/mat4x4.hpp>

#include <game_object.hpp>

class BasicRenderer : public anguish::gfx::Renderer<GameObject> {
private:
    glm::mat4 projectionMatrix{};
    glm::mat4 viewMatrix{};

public:
    BasicRenderer();

    void renderAll() override;
    void addToRenderList(std::shared_ptr<GameObject> obj) override;
};
