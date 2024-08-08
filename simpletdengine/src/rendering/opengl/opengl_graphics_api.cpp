#include <simpletdengine/rendering/opengl/opengl_graphics_api.h>
#include <simpletdengine/rendering/opengl/opengl_vertex_buffer.h>
#include <simpletdengine/rendering/opengl/opengl_index_buffer.h>
#include <simpletdengine/rendering/opengl/opengl_vertex_array.h>
#include <simpletdengine/rendering/opengl/opengl_shader.h>
#include <glad/glad.h>

namespace simpletdengine
{
    std::shared_ptr<VertexBuffer> OpenGLGraphicsAPI::CreateVertexBufer(size_t size, const void* data, const BufferLayout& layout) const
    {
        return std::make_shared<OpenGLVertexBuffer>(size, data, layout);
    }

    std::shared_ptr<IndexBuffer> OpenGLGraphicsAPI::CreateIndexBuffer(size_t size, const void* data, uint32_t count) const
    {
        return std::make_shared<OpenGLIndexBuffer>(size, data, count);
    }

    std::shared_ptr<VertexArray> OpenGLGraphicsAPI::CreateVertexArray() const
    {
        return std::make_shared<OpenGLVertexArray>();
    }

    std::shared_ptr<Shader> OpenGLGraphicsAPI::CreateShader(const std::string& vertex, const std::string& fragment) const
    {
        return std::make_shared<OpenGLShader>(vertex, fragment);
    }

    void OpenGLGraphicsAPI::SetViewport(uint32_t width, uint32_t height) const
    {
        glViewport(0, 0, width, height);
    }

    void OpenGLGraphicsAPI::DrawElements(size_t count) const
    {
        glDrawElements(GL_TRIANGLES, (GLsizei) count, GL_UNSIGNED_INT, 0);
    }
}
