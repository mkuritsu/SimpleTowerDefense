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

    private:
        static std::unique_ptr<GraphicsAPI> s_GraphicsAPI;
    };
}