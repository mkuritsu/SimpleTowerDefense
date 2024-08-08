#include <simpletdengine/rendering/opengl/opengl_utils.h>
#include <stdexcept>

namespace simpletdengine
{
    GLenum LayoutElementTypeToGLType(LayoutElementType type)
    {
        switch (type)
        {
        case LayoutElementType::FLOAT:
            return GL_FLOAT;
        default:
            throw std::runtime_error("Invalid element type!");
        }
    }
}
