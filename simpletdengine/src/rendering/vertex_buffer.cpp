#include <simpletdengine/rendering/vertex_buffer.h>

namespace simpletdengine
{
    VertexBuffer::VertexBuffer(const BufferLayout& layout) : m_Layout(layout) { }

    const BufferLayout& VertexBuffer::GetLayout() const
    {
        return m_Layout;
    }
}
