project(simpletdgame CXX)

set(GAME_SOURCES
    src/main.cpp
    src/simpletdgame.cpp
    include/simpletdgame/simpletdgame.h
)

set(GAME_INCLUDES
    include
    ../simpletdengine/include
)

set(GAME_LIBS
    simpletdengine
)

add_executable(simpletdgame ${GAME_SOURCES})

target_link_libraries(simpletdgame PRIVATE ${GAME_LIBS})

target_include_directories(simpletdgame PRIVATE ${GAME_INCLUDES})