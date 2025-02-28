cmake_minimum_required(VERSION 3.30)
project(C_Exercise C)

set(CMAKE_C_STANDARD 99)

# 包含头文件目录
include_directories(include)

# 遍历 src 目录下的所有 .c 文件
file(GLOB SOURCES "src/*.c")

# 为每个 .c 文件创建一个独立的可执行文件
foreach(source_file ${SOURCES})
    # 获取不带扩展名的文件名作为可执行文件名
    get_filename_component(exec_name ${source_file} NAME_WE)

    # 创建可执行文件
    add_executable(${exec_name} ${source_file})
endforeach()