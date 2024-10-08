#pragma once

#include <cstdint>
#include <string>

namespace simpletdengine
{
    class Shader
    {
    public:
        virtual void Bind() const = 0;

        virtual void UnBind() const = 0;

        virtual void SetInt(const std::string& uniform, int32_t value) const = 0;
        
    protected:
        uint32_t m_ID;
    };
}
