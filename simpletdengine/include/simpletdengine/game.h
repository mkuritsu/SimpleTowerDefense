#pragma once

#include <string>
#include <memory>
#include <simpletdengine/windowing/window.h>
#include <simpletdengine/defines.h>

namespace simpletdengine
{
	struct SIMPLETDENGINE_API GameWindowOptions
	{
		std::string title = "simpletdengine";
		uint32_t width = 854;
		uint32_t height = 480;
	};

	class SIMPLETDENGINE_API Game
	{
	public:
		Game(const GameWindowOptions& options);

		void Run();

	protected:

		virtual void Init();

		virtual void Update(float delta);

		virtual void Draw(float delta);

	private:
		std::unique_ptr<Window> m_Window;
	};
}