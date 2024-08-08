#pragma once

#include <vector>
#include <cstdint>
#include <cstddef>
#include <stdexcept>

namespace simpletdengine
{
    enum class LayoutElementType
    {
        FLOAT
    };

    struct LayoutElement
    {
        LayoutElementType type;
        uint32_t count;
        size_t size;

        LayoutElement(LayoutElementType type, uint32_t count, size_t size);
    };

    class BufferLayout
    {
    public:
        const std::vector<LayoutElement>& GetElements() const;

        size_t GetStride() const;

        template<typename T>
        void PushElement(uint32_t count);

    private:
        std::vector<LayoutElement> m_Elements;
        size_t m_Stride = 0;
    };
}
