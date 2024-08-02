#pragma once

#include <simpletdengine/rendering/buffer.h>
#include <memory>
#include <cstddef>

namespace simpletdengine
{
    class GraphicsAPI
    {
        virtual std::shared_ptr<Buffer> CreateBuffer(BufferType type, void* data, size_t size) const = 0;
    };
}