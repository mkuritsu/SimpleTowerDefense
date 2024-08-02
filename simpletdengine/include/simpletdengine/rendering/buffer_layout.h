#pragma once

#include <simpletdengine/rendering/layout_element.h>
#include <cstdint>
#include <vector>

namespace simpletdengine
{
	class BufferLayout
	{
	public:
		uint32_t GetStride() const;

		const std::vector<LayoutElement>& GetElements() const;

		template<typename T>
		void PushElement(uint32_t count);

	private:
		uint32_t m_Stride = 0;
		std::vector<LayoutElement> m_Elements;
	};
}