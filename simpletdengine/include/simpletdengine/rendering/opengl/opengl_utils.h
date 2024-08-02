#pragma once

#include <simpletdengine/rendering/buffer.h>
#include <simpletdengine/rendering/layout_element.h>
#include <glad/glad.h>

namespace simpletdengine
{
    GLenum BufferTypeToGLType(BufferType type);

    GLenum LayoutElementTypeToGLType(LayoutElementType type);
}