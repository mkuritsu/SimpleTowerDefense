project(simpletdgame CXX)

set(GAME_SOURCES
    src/main.cpp
)

add_executable(simpletdgame ${GAME_SOURCES})

target_link_libraries(simpletdgame PRIVATE simpletdengine)

target_include_directories(simpletdgame PRIVATE ../simpletdengine/include)