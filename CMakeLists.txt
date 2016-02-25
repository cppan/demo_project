#
# demo_project
#

cmake_minimum_required(VERSION 2.8.12)

# Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake Targets")

project(demo_project C CXX)

# Output directory settings
set(output_dir ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${output_dir})

if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
endif()

if (MSVC)
    set(disable_msvc_warnings "/W3 /wd4005 /wd4996 /wd4348 -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP ${disable_msvc_warnings}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP ${disable_msvc_warnings}")
endif()

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

#set(LIBRARY_TYPE_pvt_cppan_demo_boost_thread_1_60_0 SHARED)
#set(LIBRARY_TYPE_pvt_cppan_demo_boost_log_1_60_0 SHARED)

add_subdirectory(dep/cppan)

add_executable(main src/main.cpp)
target_link_libraries(main cppan)
if (UNIX)
    target_link_libraries(main pthread)
endif()
