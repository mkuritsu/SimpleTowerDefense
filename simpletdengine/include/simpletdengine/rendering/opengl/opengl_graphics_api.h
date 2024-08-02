#pragma once

#include <simpletdengine/rendering/graphics_api.h>

namespace simpletdengine
{
    class OpenGLGraphicsAPI : public GraphicsAPI
    {
        std::shared_ptr<Buffer> CreateBuffer(BufferType type, void* data, size_t size) const override;
    };
}