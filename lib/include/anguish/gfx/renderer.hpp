#pragma once

#include <vector>
#include <memory>

namespace anguish::gfx {
    template <class T>
    class Renderer {
    private:
        std::vector<std::shared_ptr<T>> renderList;

    protected:
        std::vector<std::shared_ptr<T>> &getRenderList() {
            return renderList;
        }

    public:
        virtual void renderAll() = 0;
        virtual void addToRenderList(std::shared_ptr<T> obj) = 0;
    };
}