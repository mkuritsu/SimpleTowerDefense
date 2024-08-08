#pragma once

#include <simpletdengine/rendering/buffer_layout.h>
#include <cstdint>

namespace simpletdengine
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const BufferLayout& layout);

        const BufferLayout& GetLayout() const;

        virtual void Bind() const = 0;

        virtual void UnBind() const = 0;

    protected:
        uint32_t m_ID;

    private:
        BufferLayout m_Layout;
    };
}
