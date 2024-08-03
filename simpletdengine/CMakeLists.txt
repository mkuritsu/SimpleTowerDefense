project(simpletdengine CXX)

option(SIMPLETDENGINE_BUILD_SHARED "Should build engine as a dynamic link library" OFF)

message("[simpletdengine] BUILD SHARED: ${SIMPLETDENGINE_BUILD_SHARED}")

set(SIMPLETDENGINE_BUILD_WINDOW_BACKED "SDL" CACHE STRING "The window backend to use")

add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/sdl)
add_subdirectory(thirdparty/stb_image)

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

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${ENGINE_SOURCES})

foreach (FILE ${ENGINE_SOURCES})
    if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}")
        message("Source file '${FILE}' not found creating it")
        file(WRITE "${FILE}")
    endif ()
endforeach ()

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

if (SIMPLETDENGINE_BUILD_SHARED)
    add_library(simpletdengine SHARED ${ENGINE_SOURCES})
    target_compile_definitions(simpletdengine PRIVATE SIMPLETDENGINE_DLL_EXPORT PUBLIC SIMPLETDENGINE_DLL_IMPORT)
else ()
    add_library(simpletdengine ${ENGINE_SOURCES})
endif ()

target_include_directories(simpletdengine PRIVATE ${ENGINE_INCLUDES})

target_link_libraries(simpletdengine PRIVATE ${ENGINE_LIBS})

target_compile_definitions(simpletdengine PRIVATE SIMPLETDENGINE_WINDOW_SDL)