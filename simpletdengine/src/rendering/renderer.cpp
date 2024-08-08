#include <simpletdengine/rendering/renderer.h>
#include <simpletdengine/rendering/opengl/opengl_graphics_api.h>
#include <stdexcept>

namespace simpletdengine
{
    Renderer::Renderer(RenderingAPI api)
    {
        switch (api)
        {
        case RenderingAPI::OPENGL:
            m_GraphicsAPI = std::make_unique<OpenGLGraphicsAPI>();
            break;
        default:
            throw std::runtime_error("Unsupported rendering api!");
        }
    }

    const std::unique_ptr<GraphicsAPI>& Renderer::GetAPI() const
    {
        return m_GraphicsAPI;
    }

    void Renderer::Draw(const std::shared_ptr<VertexArray>& object, const std::shared_ptr<Shader>& shader) const
    {
        shader->Bind();
        object->Bind();
        m_GraphicsAPI->DrawElements(object->GetIndexBuffer()->Count());
    }
}
