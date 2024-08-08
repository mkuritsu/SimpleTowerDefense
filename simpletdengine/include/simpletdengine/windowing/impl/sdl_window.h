#pragma once

#include <SDL3/SDL.h>
#include <cstdint>
#include <simpletdengine/windowing/window.h>

namespace simpletdengine
{
    class SDLWindow : public Window
    {
    public:
        SDLWindow(const std::string& title, uint32_t width, uint32_t height);

        ~SDLWindow();

        uint32_t GetWidth() const override;

        uint32_t GetHeight() const override;

        void PollEvents() override;

        void Quit() override;

        void SwapBuffers() override;

        bool ShouldQuit() const override;

        uint64_t GetTime() const override;

    private:
        bool m_ShoudlQuit = false;
        SDL_Window* m_Window = nullptr;
    };
}
