cmake_minimum_required(VERSION 3.16)

project(practica3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(practica3 main.cpp
    FuncCC.h)

include(GNUInstallDirs)
install(TARGETS practica3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
