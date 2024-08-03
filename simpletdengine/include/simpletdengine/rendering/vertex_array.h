#pragma once

#include <cstdint>
#include <simpletdengine/rendering/buffer_layout.h>

namespace simpletdengine
{
	class VertexArray
	{
	public:
		virtual void Bind() const = 0;

		virtual void SetLayout(const BufferLayout& layout) const = 0;

	protected:
		uint32_t m_ID;
	};
}