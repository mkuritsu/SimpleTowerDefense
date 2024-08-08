#include <simpletdengine/rendering/opengl/opengl_vertex_array.h>
#include <simpletdengine/rendering/opengl/opengl_utils.h>
#include <glad/glad.h>
#include <iostream>

namespace simpletdengine
{
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glGenVertexArrays(1, &m_ID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_ID);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer)
    {
        Bind();
        buffer->Bind();
        const BufferLayout& layout = buffer->GetLayout();
        const std::vector<LayoutElement>& elements = layout.GetElements();
        size_t offset = 0;
        for (uint32_t i = 0; i < elements.size(); i++)
        {
            const LayoutElement& element = elements[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, LayoutElementTypeToGLType(element.type), GL_FALSE, layout.GetStride(), (void*)offset);
            offset += element.size * element.count;
        }
        UnBind();
        VertexArray::AddVertexBuffer(buffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer)
    {
        Bind();
        buffer->Bind();
        UnBind();
        VertexArray::SetIndexBuffer(buffer);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_ID);
    }

    void OpenGLVertexArray::UnBind() const
    {
        glBindVertexArray(0);
    }
}
