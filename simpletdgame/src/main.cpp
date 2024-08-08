#include <array>
#include <iostream>
#include <simpletdgame/simpletdgame.h>
#include <unordered_set>
#include <vector>

int main()
{
    simpletdengine::GameWindowOptions options;
    options.height = options.width;
    options.title = "STD - SimpleTowerDefense";
    simpletdgame::SimpleTowerDefense game{options};
    game.Run();
    return 0;
}
