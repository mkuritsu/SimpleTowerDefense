#pragma once

#include <memory>
#include <simpletdengine/windowing/window.h>
#include <simpletdengine/rendering/renderer.h>
#include <string>

namespace simpletdengine
{
    struct GameWindowOptions
    {
        std::string title = "simpletdengine";
        uint32_t width = 854;
        uint32_t height = 480;
    };

    class Game
    {
    public:
        Game(const GameWindowOptions& options);

        void Run();

    protected:
        virtual void Init();

        virtual void Update(float delta);

        virtual void Draw(float delta);

        uint32_t GetFPS() const;

        const Renderer& GetRenderer() const;

    private:
        std::unique_ptr<Window> m_Window;
        Renderer m_Renderer;
        uint32_t m_FPS = 0;
    };
}
