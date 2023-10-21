cmake_minimum_required(VERSION 3.15...3.26)
project(${SKBUILD_PROJECT_NAME} LANGUAGES CXX)

set(PYBIND11_NEWPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)
find_package(OpenMP REQUIRED)

pybind11_add_module(ngmpy ngm_to_ngmpy.cpp)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(ngmpy PUBLIC OpenMP::OpenMP_CXX)
endif()

install(TARGETS ngmpy LIBRARY DESTINATION .)
