#include <simpletdengine/rendering/vertex_array.h>

namespace simpletdengine
{
    void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer)
    {
        m_VertexBuffers.push_back(buffer);
    }

    void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer)
    {
        m_IndexBuffer = buffer;
    }

    const std::shared_ptr<IndexBuffer> VertexArray::GetIndexBuffer() const
    {
        return m_IndexBuffer;
    }
}
