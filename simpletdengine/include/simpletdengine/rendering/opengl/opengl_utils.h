#pragma once

#include <glad/glad.h>
#include <simpletdengine/rendering/buffer.h>
#include <simpletdengine/rendering/layout_element.h>

namespace simpletdengine
{
    GLenum BufferTypeToGLType(BufferType type);

    GLenum LayoutElementTypeToGLType(LayoutElementType type);
}
