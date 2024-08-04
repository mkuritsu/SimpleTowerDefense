#include <simpletdengine/rendering/buffer.h>

namespace simpletdengine
{
    Buffer::Buffer(BufferType type) : m_Type(type)
    {
    }

    uint32_t Buffer::GetID() const
    {
        return m_ID;
    }
}
