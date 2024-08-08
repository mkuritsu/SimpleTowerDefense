#include <simpletdgame/simpletdgame.h>
#include <simpletdengine/rendering/graphics_api.h>
#include <simpletdengine/filesystem/file_utils.h>

static uint32_t s_IndexBufferData[] =
{
    0, 1, 2,
    2, 3, 0
};

static float s_VertexBufferData[] =
{
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f,
    -0.5f, 0.5f
};

namespace simpletdgame
{
    SimpleTowerDefense::SimpleTowerDefense(simpletdengine::GameWindowOptions options) : simpletdengine::Game(options) { }

    void SimpleTowerDefense::Init()
    {
        const std::unique_ptr<simpletdengine::GraphicsAPI>& api = GetRenderer().GetAPI();
        m_IndexBuffer = api->CreateIndexBuffer(sizeof(s_IndexBufferData), s_IndexBufferData, sizeof(s_IndexBufferData) / sizeof(uint32_t));
        m_VertexArray = api->CreateVertexArray();
        simpletdengine::BufferLayout layout;
        layout.PushElement<float>(2);
        m_VertexBuffer = api->CreateVertexBufer(sizeof(s_VertexBufferData), s_VertexBufferData, layout);
        m_VertexArray->SetIndexBuffer(m_IndexBuffer);
        m_VertexArray->AddVertexBuffer(m_VertexBuffer);
        std::string vertex = simpletdengine::ReadTextFile("assets/basic.vert");
        std::string fragment = simpletdengine::ReadTextFile("assets/basic.frag");
        m_Shader = api->CreateShader(vertex, fragment);
    }

    void SimpleTowerDefense::Update(float delta)
    {
    }

    void SimpleTowerDefense::Draw(float delta)
    {
        GetRenderer().Draw(m_VertexArray, m_Shader);
    }
}
