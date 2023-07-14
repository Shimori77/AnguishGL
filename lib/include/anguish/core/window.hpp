#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <cstdint>

namespace anguish::core {
    class Window {
    private:
        GLFWwindow *m_window;

    public:
        Window(const std::string &title, uint16_t width, uint16_t height, bool debugMode, bool resizable);
        ~Window();

        void setResizeCallback(GLFWwindowsizefun callback);

        [[nodiscard]] GLFWwindow *getWindow() const {
            return this->m_window;
        }
    };
}