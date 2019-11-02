cmake_minimum_required (VERSION 2.6)
project (Game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build/debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

# OpenGL
find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
		include_directories(${OpenGL_INCLUDE_DIRS})
		link_directories(${OpenGL_LIBRARY_DIRS})
		add_definitions(${OpenGL_DEFINITIONS})
endif()

# GLEW
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
		add_definitions(${GLEW_DEFINITIONS})
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

# GLFW
find_package(glfw3 REQUIRED)

# Engine
add_library(Engine SHARED Engine/engine.cpp)
target_link_libraries(Engine glfw ${OPENGL_gl_LIBRARY})
include_directories(${CMAKE_SOURCE_DIR}/Engine)
link_directories(${CMAKE_SOURCE_DIR}/Engine)

# Version number
set (Game_Version_Majnor 0)
set (Game_Version_Minorr 0)

add_executable(Game main.cpp)

target_link_libraries(Game ${OPENGL_gl_LIBRARY} glfw Engine)

target_include_directories(Game PUBLIC
                          "${PROJECT_BINARY_DIR}"
													"${PROJECT_SOURCE_DIR}/Engine"
													)

