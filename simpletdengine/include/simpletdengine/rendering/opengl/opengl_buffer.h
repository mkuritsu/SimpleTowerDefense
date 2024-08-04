#pragma once

#include <cstddef>
#include <simpletdengine/rendering/buffer.h>

namespace simpletdengine
{
    class OpenGLBuffer : public Buffer
    {
    public:
        OpenGLBuffer(BufferType type, const void* data, size_t size);

        ~OpenGLBuffer();

        void Bind() const override;
    };
}
