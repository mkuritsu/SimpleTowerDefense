#pragma once

#include <cstdint>

namespace simpletdengine
{
    enum BufferType
    {
        VERTEX_BUFFER,
        INDEX_BUFFER
    };

    class Buffer
    {
    public:
        uint32_t GetID() const;

        virtual void Bind() const = 0;

    protected:
        Buffer(BufferType type);

    protected:
        uint32_t m_ID = 0;
        BufferType m_Type;
    };
}