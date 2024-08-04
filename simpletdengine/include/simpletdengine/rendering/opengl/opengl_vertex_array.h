#pragma once

#include <simpletdengine/rendering/vertex_array.h>

namespace simpletdengine
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();

        ~OpenGLVertexArray();

        void Bind() const override;

        void SetLayout(const BufferLayout& layout) const override;
    };
}
