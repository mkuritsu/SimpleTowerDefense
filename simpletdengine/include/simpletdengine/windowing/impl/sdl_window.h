#pragma once

#include <simpletdengine/windowing/window.h>
#include <SDL3/SDL.h>

namespace simpletdengine
{
	class SDLWindow : public Window
	{
	public:
		SDLWindow(const std::string& title, uint32_t width, uint32_t height);

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