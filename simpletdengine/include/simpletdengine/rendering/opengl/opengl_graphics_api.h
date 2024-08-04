#pragma once

#include <simpletdengine/rendering/graphics_api.h>

namespace simpletdengine
{
    class OpenGLGraphicsAPI : public GraphicsAPI
    {
    public:
        std::shared_ptr<Buffer> CreateBuffer(BufferType type, const void* data, size_t size) const override;

        std::shared_ptr<VertexArray> CreateVertexArray() const override;

        std::shared_ptr<Shader> CreateShader(const std::string& vertex, const std::string& fragment) const override;

        void Draw(uint32_t indicesCount) const override;
    };
}
