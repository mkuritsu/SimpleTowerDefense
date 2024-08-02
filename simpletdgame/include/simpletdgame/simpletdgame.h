#pragma once

#include <simpletdengine/game.h>

namespace simpletdgame
{
	class SimpleTowerDefense : public simpletdengine::Game
	{
	public:
		SimpleTowerDefense(simpletdengine::GameWindowOptions options = {});

	private:
		void Init() override;

		void Update(float delta) override;

		void Draw(float delta) override;
	};
}