#pragma once

#include <simpletdengine/rendering/buffer.h>
#include <simpletdengine/rendering/vertex_array.h>
#include <memory>
#include <cstddef>

namespace simpletdengine
{
    class GraphicsAPI
    {
        virtual std::shared_ptr<Buffer> CreateBuffer(BufferType type, void* data, size_t size) const = 0;

        virtual std::shared_ptr<VertexArray> CreateVertexArray() const = 0;
    };
}