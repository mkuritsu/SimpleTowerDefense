#include <simpletdengine/rendering/opengl/opengl_index_buffer.h>
#include <glad/glad.h>

namespace simpletdengine
{
    OpenGLIndexBuffer::OpenGLIndexBuffer(size_t size, const void* data, uint32_t count) : IndexBuffer(count)
    {
        glGenBuffers(1, &m_ID);
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        UnBind();
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &m_ID);
    }

    void OpenGLIndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    }

    void OpenGLIndexBuffer::UnBind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
