set(SRCS
        "main.cpp"
        "SWindow.cpp"
        "SWindow.h")

add_subdirectory(Renderer)

source_group("src" FILES ${SRCS})
source_group("src\\renderer" FILES ${RENDERER_SRCS})

add_executable(SClone ${SRCS} ${RENDERER_SRCS})

include_directories(".")

target_link_libraries(SClone ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} glew32s opengl32)
