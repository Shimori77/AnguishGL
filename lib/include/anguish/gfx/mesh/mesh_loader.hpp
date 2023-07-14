#pragma once
#include <anguish/gfx/mesh/mesh.hpp>

#include <vector>
#include <memory>

namespace anguish::gfx::mesh {
    class MeshLoader {
    public:
        virtual std::shared_ptr<Mesh> load(
                const std::vector<uint32_t> &indices,
                const std::vector<float> &vertices,
                const std::vector<float> &textures
        );
    };
}