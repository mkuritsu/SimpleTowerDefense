project(simpletdengine CXX)

set(SIMPLETDENGINE_BUILD_WINDOW_BACKED "SDL" CACHE STRING "The window backend to use")

add_subdirectory(thirdparty/glad lib/glad)
add_subdirectory(thirdparty/glm lib/glm)
add_subdirectory(thirdparty/sdl lib/sdl)
add_subdirectory(thirdparty/stb_image lib/stb_image)

set(ENGINE_SOURCES
    src/rendering/opengl/opengl_buffer.cpp
    src/rendering/opengl/opengl_graphics_api.cpp
    src/rendering/opengl/opengl_utils.cpp
    src/rendering/opengl/opengl_vertex_array.cpp
    src/rendering/buffer.cpp
    src/rendering/buffer_layout.cpp
    src/rendering/layout_element.cpp
    src/rendering/renderer.cpp
    src/windowing/impl/sdl_window.cpp
    src/windowing/window.cpp
    src/game.cpp

    include/simpletdengine/rendering/opengl/opengl_buffer.h
    include/simpletdengine/rendering/opengl/opengl_graphics_api.h
    include/simpletdengine/rendering/opengl/opengl_utils.h
    include/simpletdengine/rendering/opengl/opengl_vertex_array.h
    include/simpletdengine/rendering/buffer.h
    include/simpletdengine/rendering/buffer_layout.h
    include/simpletdengine/rendering/graphics_api.h
    include/simpletdengine/rendering/layout_element.h
    include/simpletdengine/rendering/renderer.h
    include/simpletdengine/rendering/vertex_array.h
    include/simpletdengine/windowing/impl/sdl_window.h
    include/simpletdengine/windowing/window.h
    include/simpletdengine/defines.h
    include/simpletdengine/game.h
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