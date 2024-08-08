#pragma once

#include <vector>
#include <memory>
#include <cstdint>
#include <simpletdengine/rendering/vertex_buffer.h>
#include <simpletdengine/rendering/index_buffer.h>

namespace simpletdengine
{
    class VertexArray
    {
    public:
        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer);

        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer);

        virtual void Bind() const = 0;

        virtual void UnBind() const = 0;

        const std::shared_ptr<IndexBuffer> GetIndexBuffer() const;

    protected:
        uint32_t m_ID;

    private:
        std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    };
}
