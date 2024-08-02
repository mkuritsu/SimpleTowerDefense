project(simpletdengine CXX)

set(SIMPLETDENGINE_BUILD_WINDOW_BACKED "SDL" CACHE STRING "The window backend to use")

add_subdirectory(thirdparty/glad lib/glad)
add_subdirectory(thirdparty/glm lib/glm)
add_subdirectory(thirdparty/sdl lib/sdl)
add_subdirectory(thirdparty/stb_image lib/stb_image)

set(ENGINE_SOURCES
    src/windowing/window.cpp
    src/windowing/impl/sdl_window.cpp
    src/game.cpp
    include/simpletdengine/defines.h
    include/simpletdengine/game.h
    include/simpletdengine/windowing/window.h
    include/simpletdengine/windowing/impl/sdl_window.h
)

set(ENGINE_INCLUDES
    thirdparty/glad/include
    thirdparty/sdl/include
    thirdparty/glm/glm
    thirdparty/stb_image
    include
)

set(ENGINE_LIBS
    glad
    stb_image
    glm
    SDL3::SDL3
)

set(ENGINE_DEFINES)

IF (SIMPLETDENGINE_BUILD_WINDOW_BACKED STREQUAL "SDL")
    message("[simpletdengine] Using SDL backend")
    set(ENGINE_DEFINES ${ENGINE_DEFINES} SIMPLETDENGINE_WINDOW_SDL)
ENDIF ()

IF (BUILD_SHARED_LIBS)
    set(ENGINE_DEFINES ${ENGINE_DEFINES} SIMPLETDENGINE_BUILD_DLL)
ENDIF ()

add_library(simpletdengine ${ENGINE_SOURCES})

target_include_directories(simpletdengine PRIVATE ${ENGINE_INCLUDES})

target_link_libraries(simpletdengine PRIVATE ${ENGINE_LIBS})

target_compile_definitions(simpletdengine PRIVATE ${ENGINE_DEFINES})