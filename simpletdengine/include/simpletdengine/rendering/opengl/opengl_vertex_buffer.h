#pragma once

#include <simpletdengine/rendering/vertex_buffer.h>
#include <cstddef>

namespace simpletdengine
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(size_t size, const void* data, const BufferLayout& layout);

        ~OpenGLVertexBuffer();

        void Bind() const override;

    void UnBind() const override;

    };
}
