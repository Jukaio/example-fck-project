cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(example)

file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/**.h")

file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp")

set(FCK_LIBRARY_MODE ON)
set(FCK_RESOURCE_DIRECTORY_PATH "${CMAKE_CURRENT_SOURCE_DIR}/resources/")

FetchContent_Declare(
    fck
    GIT_REPOSITORY https://github.com/ruthenium044/fck-engine
    GIT_TAG master
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(fck)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})

target_link_libraries(${PROJECT_NAME} fck::fck)

