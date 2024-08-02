#include <simpletdengine/rendering/opengl/opengl_buffer.h>
#include <simpletdengine/rendering/opengl/opengl_utils.h>
#include <glad/glad.h>

namespace simpletdengine
{
    OpenGLBuffer::OpenGLBuffer(BufferType type, void* data, size_t size) : Buffer(type)
    {
        glGenBuffers(1, &m_ID);
        Bind();
        glBufferData(BufferTypeToGLType(m_Type), size, data, GL_STATIC_DRAW);
    }

    OpenGLBuffer::~OpenGLBuffer()
    {
        glDeleteBuffers(1, &m_ID);
    }

    void OpenGLBuffer::Bind() const
    {
        glBindBuffer(BufferTypeToGLType(m_Type), m_ID);
    }
}