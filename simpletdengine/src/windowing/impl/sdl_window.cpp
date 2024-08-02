#include <simpletdengine/windowing/impl/sdl_window.h>
#include <stdexcept>
#include <glad/glad.h>

namespace simpletdengine
{
	SDLWindow::SDLWindow(const std::string& title, uint32_t width, uint32_t height)
	{
		if (SDL_Init(SDL_INIT_VIDEO) == -1)
		{
			throw std::runtime_error("Failed to initialize SDL!");
		}
		m_Window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		if (!m_Window)
		{
			throw std::runtime_error("Failed to create SDL window!");
		}
		SDL_GLContext glContext = SDL_GL_CreateContext(m_Window);
		if (!glContext)
		{
			throw std::runtime_error("Failed to create OpenGL context!");
		}
		SDL_GL_MakeCurrent(m_Window, glContext);
		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			throw std::runtime_error("Failed to load OpenGL functions!");
		}
	}

	uint32_t SDLWindow::GetWidth() const
	{
		int width;
		SDL_GetWindowSize(m_Window, &width, NULL);
		return width;
	}

	uint32_t SDLWindow::GetHeight() const
	{
		int height;
		SDL_GetWindowSize(m_Window, NULL, &height);
		return height;
	}

	void SDLWindow::PollEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				m_ShoudlQuit = true;
			}
		}
	}

	void SDLWindow::Destroy() const
	{
		SDL_DestroyWindow(m_Window);
	}

	void SDLWindow::Quit()
	{
		m_ShoudlQuit = true;
	}

	void SDLWindow::SwapBuffers()
	{
		SDL_GL_SwapWindow(m_Window);
	}

	bool SDLWindow::ShouldQuit() const
	{
		return m_ShoudlQuit;
	}

	float SDLWindow::GetTime() const
	{
		return SDL_GetTicks() / 1000.0f;
	}
}