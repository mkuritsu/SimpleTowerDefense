#include <iostream>
#include <simpletdengine/game.h>

int main()
{
    simpletdengine::GameWindowOptions options = simpletdengine::GameWindowOptions::Default();
    simpletdengine::Game game(options);
    game.Run();
    return 0;
}