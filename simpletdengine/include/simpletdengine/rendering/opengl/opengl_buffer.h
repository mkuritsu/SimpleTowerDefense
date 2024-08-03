#pragma once

#include <simpletdengine/rendering/buffer.h>
#include <cstddef>

namespace simpletdengine
{
    class OpenGLBuffer : public Buffer
    {
    public:
        OpenGLBuffer(BufferType type, void* data, size_t size);

        ~OpenGLBuffer();

        void Bind() const override;
    };
}