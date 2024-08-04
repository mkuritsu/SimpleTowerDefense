#include <simpletdengine/windowing/window.h>

#ifdef SIMPLETDENGINE_WINDOW_SDL
#include <simpletdengine/windowing/impl/sdl_window.h>
#else
#error No window backend selected!
#endif

namespace simpletdengine
{
    std::unique_ptr<Window> Window::Create(const std::string& title, uint32_t width, uint32_t height)
    {
#ifdef SIMPLETDENGINE_WINDOW_SDL
        return std::make_unique<SDLWindow>(title, width, height);
#endif
    }
}
