#include <simpletdengine/windowing/window.h>
#include <simpletdengine/windowing/impl/sdl_window.h>

namespace simpletdengine
{
    std::unique_ptr<Window> Window::Create(const std::string& title, uint32_t width, uint32_t height)
    {
        return std::make_unique<SDLWindow>(title, width, height);
    }
}
