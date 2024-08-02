#include <simpletdengine/rendering/buffer_layout.h>

namespace simpletdengine
{
	uint32_t BufferLayout::GetStride() const
	{
		return m_Stride;
	}

	const std::vector<LayoutElement>& BufferLayout::GetElements() const
	{
		return m_Elements;
	}

	template<>
	void BufferLayout::PushElement<float>(uint32_t count)
	{
		LayoutElement element(LayoutElementType::FLOAT, sizeof(float), count);
		m_Elements.push_back(element);
		m_Stride += element.GetCount() * element.GetSize();
	}
}