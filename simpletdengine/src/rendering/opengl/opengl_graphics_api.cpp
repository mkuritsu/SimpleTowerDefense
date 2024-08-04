#include <glad/glad.h>
#include <simpletdengine/rendering/opengl/opengl_buffer.h>
#include <simpletdengine/rendering/opengl/opengl_graphics_api.h>
#include <simpletdengine/rendering/opengl/opengl_shader.h>
#include <simpletdengine/rendering/opengl/opengl_vertex_array.h>

namespace simpletdengine
{
    std::shared_ptr<Buffer> OpenGLGraphicsAPI::CreateBuffer(BufferType type, const void* data, size_t size) const
    {
        return std::make_shared<OpenGLBuffer>(type, data, size);
    }

    std::shared_ptr<VertexArray> OpenGLGraphicsAPI::CreateVertexArray() const
    {
        return std::make_shared<OpenGLVertexArray>();
    }

    std::shared_ptr<Shader> OpenGLGraphicsAPI::CreateShader(const std::string& vertex, const std::string& fragment) const
    {
        return std::make_shared<OpenGLShader>(vertex, fragment);
    }

    void OpenGLGraphicsAPI::Draw(uint32_t indicesCount) const
    {
        glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, NULL);
    }
}
