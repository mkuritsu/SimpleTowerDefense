#include <simpletdengine/rendering/renderer.h>
#include <simpletdengine/rendering/opengl/opengl_graphics_api.h>
#include <cassert>

namespace simpletdengine
{
    std::unique_ptr<GraphicsAPI> Renderer::s_GraphicsAPI = nullptr;

    void Renderer::Init(RenderingAPI api)
    {
        switch (api)
        {
        case RenderingAPI::OPENGL:
            s_GraphicsAPI = std::make_unique<OpenGLGraphicsAPI>();
            break;
        }
    }

    const std::unique_ptr<GraphicsAPI>& Renderer::GetAPI()
    {
        assert(s_GraphicsAPI != nullptr);
        return s_GraphicsAPI;
    }
}