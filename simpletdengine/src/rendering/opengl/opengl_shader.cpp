#include <simpletdengine/rendering/opengl/opengl_shader.h>
#include <glad/glad.h>
#include <iostream>

namespace simpletdengine
{
    OpenGLShader::OpenGLShader(const std::string& vertex, const std::string& fragment)
    {
        std::cout << "Vertex:\n" << vertex << "\nFragment:\n" << fragment << std::endl;
        m_ID = glCreateProgram();
        uint32_t vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const char* vertexSource = vertex.c_str();
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);
        uint32_t fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const char* fragmentSource = fragment.c_str();
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);
        glAttachShader(m_ID, vertexShader);
        glAttachShader(m_ID, fragmentShader);
        glLinkProgram(m_ID);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_ID);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_ID);
    }

    void OpenGLShader::UnBind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::SetInt(const std::string& name, int32_t value) const
    {
        uint32_t loc = glGetUniformLocation(m_ID, name.c_str());
        glUniform1i(loc, value);
    }
}
