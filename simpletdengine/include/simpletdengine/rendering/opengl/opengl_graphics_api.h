#pragma once

#include <simpletdengine/rendering/graphics_api.h>

namespace simpletdengine
{
    class OpenGLGraphicsAPI : public GraphicsAPI
    {
        std::shared_ptr<VertexBuffer> CreateVertexBufer(size_t size, const void* data, const BufferLayout& layout) const override;

        std::shared_ptr<IndexBuffer> CreateIndexBuffer(size_t size, const void* data, uint32_t count) const override;

        std::shared_ptr<VertexArray> CreateVertexArray() const override;

        std::shared_ptr<Shader> CreateShader(const std::string& vertex, const std::string& fragment) const override;

        void SetViewport(uint32_t width, uint32_t height) const override;

        void DrawElements(size_t count) const override;
    };
}
