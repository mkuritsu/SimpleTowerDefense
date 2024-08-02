#include <simpletdengine/rendering/layout_element.h>

namespace simpletdengine
{
	LayoutElement::LayoutElement(LayoutElementType type, uint32_t size, uint32_t count) : m_Type(type), m_Count(count) { }

	uint32_t LayoutElement::GetCount() const
	{
		return m_Count;
	}

	uint32_t LayoutElement::GetSize() const
	{
		return m_Size;
	}

	LayoutElementType LayoutElement::GetType() const
	{
		return m_Type;
	}
}