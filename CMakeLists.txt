#
# demo_project
#

cmake_minimum_required(VERSION 2.8.12)

# Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake Targets")

project(demo_project C CXX)

if (MSVC)
    set(disable_msvc_warnings "/W3 /wd4005 /wd4996 /wd4348 -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP ${disable_msvc_warnings}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP ${disable_msvc_warnings}")
endif()

add_subdirectory(dep/cppan)

add_executable(main src/main.cpp)
target_link_libraries(main cppan)
