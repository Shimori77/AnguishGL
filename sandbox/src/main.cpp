#include <anguish/core/window.hpp>
#include <anguish/gfx/mesh/mesh_loader.hpp>
#include <anguish/gfx/shader/shader_loader.hpp>
#include <anguish/gfx/texture/texture_loader.hpp>

#include <basic_shader.hpp>
#include <basic_renderer.hpp>

#include <string>

template class anguish::gfx::shader::ShaderLoader<BasicShader>;

int main() {
    using namespace anguish;

    std::string title("AnguishGL v0.1.0");
    core::Window window(title, 1366, 768, true, false);

    gfx::mesh::MeshLoader meshLoader;
    gfx::texture::TextureLoader textureLoader;
    BasicShaderLoader basicShaderLoader;
    BasicRenderer basicRenderer;

    std::vector<uint32_t> indices {
        0, 1, 2,
        2, 3, 0
    };

    std::vector<float> vertices {
        -1,-1,
        1,-1,
        1,1,
        -1,1
    };

    std::vector<float> textures {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };

    std::shared_ptr<gfx::mesh::Mesh> quadMesh = meshLoader.load(indices, vertices, textures);
    std::shared_ptr<BasicShader> basicShaderProgram = basicShaderLoader.loadShaderProgram(
            "resources/basic.vert",
            "resources/basic.frag"
    );

    std::shared_ptr<gfx::texture::Texture> quadTexture = textureLoader.loadTexture2D("resources/textures/brick.png");
    std::shared_ptr<GameObject> quadObj = std::make_shared<GameObject>(
            quadMesh, quadTexture, basicShaderProgram,
            glm::vec3(1366 / 2, 768 / 2, 0), glm::vec3(0), glm::vec2(1366, 768)
    );

    basicRenderer.addToRenderList(quadObj);

    while (!glfwWindowShouldClose(window.getWindow())) {
        glClear(GL_COLOR_BUFFER_BIT);

        basicRenderer.renderAll();

        quadObj->setRotation(glm::vec3(0, 0, quadObj->getRotation().z + 0.50f));

        glfwSwapBuffers(window.getWindow());
        glfwPollEvents();
    }
    return 0;
}