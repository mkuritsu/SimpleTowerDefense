#include <simpletdengine/rendering/opengl/opengl_vertex_array.h>
#include <simpletdengine/rendering/opengl/opengl_utils.h>
#include <glad/glad.h>

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

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_ID);
	}

	void OpenGLVertexArray::SetLayout(const BufferLayout& layout) const
	{
		uint32_t stride = layout.GetStride();
		uint32_t index = 0;
		uint32_t offset = 0;
		for (const LayoutElement& elem : layout.GetElements())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, elem.GetCount(), LayoutElementTypeToGLType(elem.GetType()), GL_FALSE, stride, (void*)offset);
			offset += elem.GetCount() * elem.GetSize();
			index++;
		}
	}
}