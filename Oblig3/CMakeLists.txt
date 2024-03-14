cmake_minimum_required(VERSION 3.5)

project(Oblig3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Oblig3 main.cpp
    oblig3_mbb.h oblig3_mbb.cpp)

include(GNUInstallDirs)
install(TARGETS Oblig3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
