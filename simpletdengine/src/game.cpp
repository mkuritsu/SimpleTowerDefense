#include <simpletdengine/game.h>
#include <simpletdengine/rendering/renderer.h>
#include <cstdint>

namespace simpletdengine
{
    Game::Game(const GameWindowOptions& options) 
        : m_Window(Window::Create(options.title, options.width, options.height)), m_Renderer(RenderingAPI::OPENGL)
    {
    }

    void Game::Run()
    {
        Init();
        uint64_t lastTime = 0;
        uint32_t fps = 0;
        uint64_t lastFrame = 0;
        while (!m_Window->ShouldQuit())
        {
            uint64_t now = m_Window->GetTime();
            uint64_t diff = now - lastTime;
            lastFrame += diff;
            lastTime = now;
            fps++;
            if (lastFrame >= 1000)
            {
                m_FPS = fps;
                fps = 0;
                lastFrame = 0;
            }
            float delta = diff / 1000.0f;
            m_Window->PollEvents();
            uint32_t width = m_Window->GetWidth();
            uint32_t height = m_Window->GetHeight();
            m_Renderer.GetAPI()->SetViewport(width, height);
            Update(delta);
            Draw(delta);
            m_Window->SwapBuffers();
        }
    }

    void Game::Init() { }

    void Game::Update(float delta) { }

    void Game::Draw(float delta) { }

    uint32_t Game::GetFPS() const
    {
        return m_FPS;
    }

    const Renderer& Game::GetRenderer() const
    {
        return m_Renderer;
    }
}
