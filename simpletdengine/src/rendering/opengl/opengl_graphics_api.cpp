#include <simpletdengine/rendering/opengl/opengl_graphics_api.h>
#include <simpletdengine/rendering/opengl/opengl_buffer.h>
#include <simpletdengine/rendering/opengl/opengl_vertex_array.h>
#include <glad/glad.h>

namespace simpletdengine
{
    std::shared_ptr<Buffer> OpenGLGraphicsAPI::CreateBuffer(BufferType type, void* data, size_t size) const
    {
        return std::make_shared<OpenGLBuffer>(type, data, size);
    }

    std::shared_ptr<VertexArray> OpenGLGraphicsAPI::CreateVertexArray() const
    {
        return std::make_shared<OpenGLVertexArray>();
    }
}