#include <simpletdgame/simpletdgame.h>
#include <simpletdengine/rendering/renderer.h>
#include <fstream>
#include <iostream>
#include <sstream>

static const float s_VBOData[] =
{
	-0.5f, 0.0f,
	0.5f, 0.0f,
	0.0f, 0.5f
};

static const unsigned int s_IndexData[] =
{
	0, 1, 2
};

namespace simpletdgame
{
	SimpleTowerDefense::SimpleTowerDefense(simpletdengine::GameWindowOptions options) : simpletdengine::Game(options) { }

	void SimpleTowerDefense::Init()
	{
		m_VertexArray = simpletdengine::Renderer::GetAPI()->CreateVertexArray();
		m_VertexArray->Bind();
		m_VertexBuffer = simpletdengine::Renderer::GetAPI()->CreateBuffer(simpletdengine::BufferType::VERTEX_BUFFER, s_VBOData, sizeof(s_VBOData));
		m_VertexBuffer->Bind();
		simpletdengine::BufferLayout layout;
		layout.PushElement<float>(2);
		m_VertexArray->SetLayout(layout);
		m_IndexBuffer = simpletdengine::Renderer::GetAPI()->CreateBuffer(simpletdengine::BufferType::INDEX_BUFFER, s_IndexData, sizeof(s_IndexData));
		m_IndexBuffer->Bind();

		std::ifstream vertexFile("assets/basic.vert");
		std::stringstream ss;
		ss << vertexFile.rdbuf();
		std::string vertexSource = ss.str();
		ss.clear();
		std::ifstream fragmentFile("asserts/basic.frag");
		ss << fragmentFile.rdbuf();
		std::string fragmentSource = ss.str();
		m_Shader = simpletdengine::Renderer::GetAPI()->CreateShader(vertexSource, fragmentSource);
	}

	void SimpleTowerDefense::Update(float delta)
	{

	}

	void SimpleTowerDefense::Draw(float delta)
	{
		simpletdengine::Renderer::Draw(m_VertexArray, 3, m_Shader);
	}
}
