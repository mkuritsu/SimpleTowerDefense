#include <simpletdengine/rendering/index_buffer.h>

namespace simpletdengine
{
    IndexBuffer::IndexBuffer(size_t count) : m_Count(count) { }

    size_t IndexBuffer::Count() const
    {
        return m_Count;
    }
}
