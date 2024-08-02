#pragma once

#include <string>
#include <cstdint>
#include <memory>

namespace simpletdengine
{
	class Window
	{
	public:

		virtual uint32_t GetWidth() const = 0;

		virtual uint32_t GetHeight() const = 0;

		virtual void PollEvents() = 0;

		virtual void Destroy() const = 0;

		virtual void Quit() = 0;

		virtual void SwapBuffers() = 0;

		virtual bool ShouldQuit() const = 0;

		virtual float GetTime() const = 0;

		static std::unique_ptr<Window> Create(const std::string& title, uint32_t width, uint32_t height);
	};
}