#pragma once

#include <simpletdengine/rendering/index_buffer.h>
#include <cstddef>

namespace simpletdengine
{
    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(size_t size, const void* data, uint32_t count);

        virtual ~OpenGLIndexBuffer();

        void Bind() const override;

        void UnBind() const override;
    };
}
