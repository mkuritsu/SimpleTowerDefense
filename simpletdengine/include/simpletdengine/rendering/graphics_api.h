#pragma once

#include <cstddef>
#include <memory>
#include <simpletdengine/rendering/buffer.h>
#include <simpletdengine/rendering/shader.h>
#include <simpletdengine/rendering/vertex_array.h>
#include <string>

namespace simpletdengine
{
    class GraphicsAPI
    {
    public:
        virtual std::shared_ptr<Buffer> CreateBuffer(BufferType type, const void* data, size_t size) const = 0;

        virtual std::shared_ptr<VertexArray> CreateVertexArray() const = 0;

        virtual std::shared_ptr<Shader> CreateShader(const std::string& vertex, const std::string& fragment) const = 0;

        virtual void Draw(uint32_t indicesCount) const = 0;
    };
}
