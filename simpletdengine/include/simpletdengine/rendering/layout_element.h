#pragma once

#include <cstdint>

namespace simpletdengine
{
	enum LayoutElementType
	{
		FLOAT
	};

	class LayoutElement
	{
	public:
		LayoutElement(LayoutElementType type, uint32_t size, uint32_t count);

		uint32_t GetSize() const;

		LayoutElementType GetType() const;

		uint32_t GetCount() const;

	private:
		LayoutElementType m_Type;
		uint32_t m_Count;
		uint32_t m_Size;
	};
}