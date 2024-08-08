project(simpletdengine CXX)

option(SIMPLETDENGINE_BUILD_SHARED "Should build engine as a dynamic link library" OFF)

set(SIMPLETDENGINE_BUILD_WINDOW_BACKEND "SDL" CACHE STRING "The window backend to use (possible options: SDL)")
set_property(CACHE SIMPLETDENGINE_BUILD_WINDOW_BACKEND PROPERTY STRINGS "SDL")

message("[simpletdengine] BUILD SHARED: ${SIMPLETDENGINE_BUILD_SHARED}")
message("[simpletdengine] Window backend: ${SIMPLETDENGINE_BUILD_WINDOW_BACKED}")

set(ENGINE_SUBDIRS
    thirdparty/glad
    thirdparty/glm
    thirdparty/sdl
    thirdparty/stb_image
)

foreach(SUBDIR ${ENGINE_SUBDIRS})
    add_subdirectory(${SUBDIR})
endforeach()

set(ENGINE_SOURCES
    src/filesystem/file_utils.cpp
    src/rendering/opengl/opengl_graphics_api.cpp
    src/rendering/opengl/opengl_index_buffer.cpp
    src/rendering/opengl/opengl_shader.cpp
    src/rendering/opengl/opengl_utils.cpp
    src/rendering/opengl/opengl_vertex_array.cpp
    src/rendering/opengl/opengl_vertex_buffer.cpp
    src/rendering/buffer_layout.cpp
    src/rendering/index_buffer.cpp
    src/rendering/renderer.cpp
    src/rendering/vertex_buffer.cpp
    src/rendering/vertex_array.cpp
    src/windowing/impl/sdl_window.cpp
    src/windowing/window.cpp
    src/game.cpp

    include/simpletdengine/filesystem/file_utils.h
    include/simpletdengine/rendering/opengl/opengl_graphics_api.h
    include/simpletdengine/rendering/opengl/opengl_index_buffer.h
    include/simpletdengine/rendering/opengl/opengl_shader.h
    include/simpletdengine/rendering/opengl/opengl_utils.h
    include/simpletdengine/rendering/opengl/opengl_vertex_array.h
    include/simpletdengine/rendering/opengl/opengl_vertex_buffer.h
    include/simpletdengine/rendering/buffer_layout.h
    include/simpletdengine/rendering/graphics_api.h
    include/simpletdengine/rendering/index_buffer.h
    include/simpletdengine/rendering/renderer.h
    include/simpletdengine/rendering/vertex_array.h
    include/simpletdengine/rendering/vertex_buffer.h
    include/simpletdengine/windowing/impl/sdl_window.h
    include/simpletdengine/windowing/window.h
    include/simpletdengine/game.h
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${ENGINE_SOURCES})

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

if(SIMPLETDENGINE_BUILD_SHARED)
    add_library(simpletdengine SHARED ${ENGINE_SOURCES})
    target_compile_definitions(simpletdengine PRIVATE SIMPLETDENGINE_DLL_EXPORT PUBLIC SIMPLETDENGINE_DLL_IMPORT)
else()
    add_library(simpletdengine ${ENGINE_SOURCES})
endif()

target_include_directories(simpletdengine PRIVATE ${ENGINE_INCLUDES})

target_link_libraries(simpletdengine PRIVATE ${ENGINE_LIBS})

target_compile_definitions(simpletdengine PRIVATE SIMPLETDENGINE_WINDOW_SDL)
