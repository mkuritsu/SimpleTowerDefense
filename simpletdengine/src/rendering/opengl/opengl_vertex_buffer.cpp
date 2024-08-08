#include <simpletdengine/rendering/opengl/opengl_vertex_buffer.h>
#include <glad/glad.h>

namespace simpletdengine
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(size_t size, const void* data, const BufferLayout& layout) : VertexBuffer(layout)
    {
        glGenBuffers(1, &m_ID);
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        UnBind();
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &m_ID);
    }
    
    void OpenGLVertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    }

    void OpenGLVertexBuffer::UnBind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}
