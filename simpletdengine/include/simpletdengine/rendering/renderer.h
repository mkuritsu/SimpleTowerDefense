#pragma once

#include <memory>
#include <simpletdengine/rendering/graphics_api.h>
#include <simpletdengine/rendering/vertex_array.h>
#include <simpletdengine/rendering/shader.h>

namespace simpletdengine
{
    enum class RenderingAPI
    {
        OPENGL
    };

    class Renderer
    {
    public:
        Renderer(RenderingAPI api);

        const std::unique_ptr<GraphicsAPI>& GetAPI() const;

        void Draw(const std::shared_ptr<VertexArray>& object, const std::shared_ptr<Shader>& shader) const;

    private:
        std::unique_ptr<GraphicsAPI> m_GraphicsAPI;
    };
}
