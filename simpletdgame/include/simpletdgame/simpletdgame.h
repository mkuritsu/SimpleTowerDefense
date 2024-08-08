#include <simpletdengine/game.h>
#include <simpletdengine/rendering/vertex_buffer.h>
#include <simpletdengine/rendering/vertex_array.h>
#include <simpletdengine/rendering/index_buffer.h>

namespace simpletdgame
{
    class SimpleTowerDefense : public simpletdengine::Game
    {
    public:
        SimpleTowerDefense(simpletdengine::GameWindowOptions options);

        void Init() override;

        void Update(float delta) override;

        void Draw(float delta) override;

    private:
        std::shared_ptr<simpletdengine::VertexBuffer> m_VertexBuffer;
        std::shared_ptr<simpletdengine::VertexArray> m_VertexArray;
        std::shared_ptr<simpletdengine::IndexBuffer> m_IndexBuffer;
        std::shared_ptr<simpletdengine::Shader> m_Shader;
    };
}
