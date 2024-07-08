include(FetchContent)

cmake_minimum_required(VERSION 3.5)
project(tryApp)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        b50e685db996c167e6c831dcef582aba6e14276a)
FetchContent_MakeAvailable(fmt)

add_executable(tryApp main.cpp)

target_include_directories(tryApp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/build/_deps/libname/include
)

target_link_libraries(tryApp fmt::fmt)