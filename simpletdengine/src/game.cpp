#include <simpletdengine/game.h>

namespace simpletdengine
{
	Game::Game(const GameWindowOptions& options) : m_Window(Window::Create(options.title, options.width, options.height)) { }

	void Game::Run()
	{
		Init();
		while (!m_Window->ShouldQuit())
		{
			float delta = m_Window->GetTime();
			m_Window->PollEvents();
			Update(delta);
			Draw(delta);
			m_Window->SwapBuffers();
		}
		m_Window->Destroy();
	}

	void Game::Init() { }

	void Game::Update(float delta) { }

	void Game::Draw(float delta) { }
}