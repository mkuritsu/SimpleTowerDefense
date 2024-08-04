#pragma once

#include <glad/glad.h>
#include <simpletdengine/rendering/shader.h>
#include <string>

namespace simpletdengine
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string& vertex, const std::string& fragment);

        ~OpenGLShader();

        void Bind() const override;

    private:
        uint32_t CreateShader(GLenum type, const std::string& source) const;
    };
}
