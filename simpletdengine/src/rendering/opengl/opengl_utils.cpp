#include <simpletdengine/rendering/opengl/opengl_utils.h>

namespace simpletdengine
{
    GLenum BufferTypeToGLType(BufferType type)
    {
        switch (type)
        {
        case BufferType::VERTEX_BUFFER:
            return GL_ARRAY_BUFFER;

        case BufferType::INDEX_BUFFER:
            return GL_ELEMENT_ARRAY_BUFFER;
        }
    }

    GLenum LayoutElementTypeToGLType(LayoutElementType type)
    {
        switch (type)
        {
        case LayoutElementType::FLOAT:
            return GL_FLOAT;
        }
    }
}
