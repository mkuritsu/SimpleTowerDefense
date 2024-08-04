#include <glad/glad.h>
#include <simpletdengine/rendering/opengl/opengl_shader.h>

namespace simpletdengine
{
    OpenGLShader::OpenGLShader(const std::string& vertex, const std::string& fragment)
    {
        m_ID = glCreateProgram();
        uint32_t vertexShader = CreateShader(GL_VERTEX_SHADER, vertex);
        uint32_t fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragment);
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

    uint32_t OpenGLShader::CreateShader(GLenum type, const std::string& source) const
    {
        uint32_t shader = glCreateShader(type);
        const char* sourceCString = source.c_str();
        glShaderSource(shader, 1, &sourceCString, NULL);
        glCompileShader(shader);
        return shader;
    }
}
