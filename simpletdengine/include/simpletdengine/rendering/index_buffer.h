#pragma once

#include <cstdint>

namespace simpletdengine
{
    class IndexBuffer
    {
    public:
        IndexBuffer(size_t count);

        size_t Count() const;

        virtual void Bind() const = 0;

        virtual void UnBind() const = 0;

    protected:
        uint32_t m_ID;
        size_t m_Count;
    };
}
