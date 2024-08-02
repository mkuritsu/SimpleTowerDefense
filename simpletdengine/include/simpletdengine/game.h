#pragma once

#include <string>
#include <memory>
#include <simpletdengine/windowing/window.h>

namespace simpletdengine
{
	struct GameWindowOptions
	{
		std::string title;
		uint32_t width;
		uint32_t height;

		static GameWindowOptions Default()
		{
			GameWindowOptions options;
			options.title = "simpletdengine";
			options.width = 854;
			options.height = 480;
			return options;
		}
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

	private:
		std::unique_ptr<Window> m_Window;
	};
}