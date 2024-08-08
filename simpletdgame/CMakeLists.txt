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

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${GAME_SOURCES})

foreach(FILE ${ENGINE_SOURCES})
    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}")
        message("Source file '${FILE}' not found creating it")
        file(WRITE "${FILE}")
    endif()
endforeach()

add_executable(simpletdgame ${GAME_SOURCES})

target_link_libraries(simpletdgame PRIVATE ${GAME_LIBS})

target_include_directories(simpletdgame PRIVATE ${GAME_INCLUDES})

if(SIMPLETDENGINE_BUILD_SHARED)
    add_custom_command(TARGET simpletdgame POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:simpletdengine>" $<TARGET_FILE_DIR:simpletdgame>)
endif()
