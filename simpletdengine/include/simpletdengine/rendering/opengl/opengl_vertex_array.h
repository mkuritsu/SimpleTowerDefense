#pragma once

#include <simpletdengine/rendering/vertex_array.h>

namespace simpletdengine
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();

        ~OpenGLVertexArray();

        void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer) override;

        void SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) override;

        void Bind() const override;

        void UnBind() const override;
    };
}
