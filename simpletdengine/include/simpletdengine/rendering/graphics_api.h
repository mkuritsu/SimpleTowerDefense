#pragma once

#include <memory>
#include <string>
#include <cstdint>
#include <simpletdengine/rendering/index_buffer.h>
#include <simpletdengine/rendering/vertex_buffer.h>
#include <simpletdengine/rendering/vertex_array.h>
#include <simpletdengine/rendering/shader.h>

namespace simpletdengine
{
    class GraphicsAPI
    {
    public:
        virtual std::shared_ptr<VertexBuffer> CreateVertexBufer(size_t size, const void* data, const BufferLayout& layout) const = 0;

        virtual std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size, const void* data, uint32_t count) const = 0;

        virtual std::shared_ptr<VertexArray> CreateVertexArray() const = 0;

        virtual std::shared_ptr<Shader> CreateShader(const std::string& vertex, const std::string& fragment) const = 0;

        virtual void SetViewport(uint32_t width, uint32_t height) const = 0;

        virtual void DrawElements(size_t count) const = 0;
    };
}
