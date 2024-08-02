#pragma once

#include <simpletdengine/windowing/window.h>
#include <simpletdengine/defines.h>
#include <SDL3/SDL.h>

namespace simpletdengine
{
	SIMPLETDENGINE_API class SDLWindow : public Window
	{
	public:
		SDLWindow(const std::string& title, uint32_t width, uint32_t height);

		~SDLWindow();

		uint32_t GetWidth() const;
		
		uint32_t GetHeight() const;

		void PollEvents();

		void Destroy() const;

		void Quit();

		void SwapBuffers();

		bool ShouldQuit() const;

		float GetTime() const;

	private:
		bool m_ShoudlQuit = false;
		SDL_Window* m_Window = nullptr;
	};
}