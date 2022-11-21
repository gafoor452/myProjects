cmake_minimum_required(VERSION 3.0.0)
project(adapterPugixml VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SOURCES
    src/*.hpp
    src/*.cpp
    pugixml_src/*.hpp
    pugixml_src/*.cpp
)

add_executable(adapterPugixml ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
