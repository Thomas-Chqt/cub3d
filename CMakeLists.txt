# ---------------------------------------------------
# CMakeLists.txt
#
# Author: Thomas Choquet <semoir.dense-0h@icloud.com>
# Date: 2024/08/01 15:34:08
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.16)

if(APPLE)
    option(CUB_FORCE_OPENGL "force use opengl over metal" OFF)
endif()

project(cub3d)

enable_language(C)

add_executable(cub3d)

file(GLOB_RECURSE CUB_SOURCES
    "Graphics/sources/*.c" "Graphics/includes/*.h"
    "Libft/sources/*.c"    "Libft/includes/*.h"
    "sources/*.c"          "includes/*.h"
)
target_sources(cub3d PRIVATE ${CUB_SOURCES})

target_include_directories(cub3d PRIVATE "Graphics/includes" "Libft/includes" "includes")

if(WIN32)
    target_include_directories(cub3d PRIVATE "unistd")
endif()

find_program(GIT_PATH git REQUIRED)
execute_process(COMMAND ${GIT_PATH} submodule update --init MinilibX WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(MLX_FORCE_OPENGL ${CUB_FORCE_OPENGL})
add_subdirectory("MinilibX")

if(TARGET MLX_MetalShaderLibrary)
    set_target_properties(mlx PROPERTIES FOLDER "dependencies/MiniLibX")
    set_target_properties(MLX_MetalShaderLibrary PROPERTIES FOLDER "dependencies/MiniLibX")
else()
    set_target_properties(mlx PROPERTIES FOLDER "dependencies")
endif()

target_link_libraries(cub3d mlx)

target_include_directories(cub3d PRIVATE "MinilibX/include/mlx")