#pragma once

#include <simpletdengine/game.h>
#include <simpletdengine/rendering/buffer.h>
#include <simpletdengine/rendering/shader.h>
#include <simpletdengine/rendering/vertex_array.h>

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

		std::shared_ptr<simpletdengine::Buffer> m_VertexBuffer;
		std::shared_ptr<simpletdengine::Buffer> m_IndexBuffer;
		std::shared_ptr<simpletdengine::Shader> m_Shader;
		std::shared_ptr<simpletdengine::VertexArray> m_VertexArray;
	};
}
