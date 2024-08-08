#include <simpletdengine/rendering/buffer_layout.h>

namespace simpletdengine
{
    LayoutElement::LayoutElement(LayoutElementType type, uint32_t count, size_t size) : type(type), count(count), size(size) { }
    
    const std::vector<LayoutElement>& BufferLayout::GetElements() const
    {
        return m_Elements;
    }

    size_t BufferLayout::GetStride() const
    {
        return m_Stride;
    }

    template<>
    void BufferLayout::PushElement<float>(uint32_t count)
    {
        m_Elements.emplace_back(LayoutElementType::FLOAT, count, sizeof(float));
        m_Stride += sizeof(float) * count;
    }
}
