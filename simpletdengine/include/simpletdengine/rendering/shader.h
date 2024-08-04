#pragma once

#include <cstdint>

namespace simpletdengine
{
    class Shader
    {
    public:
        virtual void Bind() const = 0;

    protected:
        uint32_t m_ID;
    };
}
