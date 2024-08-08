#pragma once

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

        void UnBind() const override;

        void SetInt(const std::string& uniform, int32_t value) const override;
    };
}
