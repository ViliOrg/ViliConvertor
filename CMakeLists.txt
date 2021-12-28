cmake_minimum_required(VERSION 3.12)

project(vilicvt)

file(GLOB VILI_CVT_HEADERS include/vilicvt/*.hpp)
file(GLOB VILI_CVT_SOURCES src/*.cpp)

add_executable(vilicvt ${VILI_CVT_HEADERS} ${VILI_CVT_SOURCES})

add_subdirectory(extlibs/lyra)
add_subdirectory(extlibs/vili)

target_link_libraries(vilicvt lyra)
target_link_libraries(vilicvt vili)

target_include_directories(vilicvt
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/vilicvt>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extlibs>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)