#pragma once

#include <memory>
#include <simpletdengine/rendering/graphics_api.h>

namespace simpletdengine
{
    enum RenderingAPI
    {
        OPENGL
    };

    class Renderer
    {
    public:
        static void Init(RenderingAPI api);

        static const std::unique_ptr<GraphicsAPI>& GetAPI();

        static void Draw(const std::shared_ptr<VertexArray>& object, uint32_t indicesCount, const std::shared_ptr<Shader>& shader);

    private:
        static std::unique_ptr<GraphicsAPI> s_GraphicsAPI;
    };
}
