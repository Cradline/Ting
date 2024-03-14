cmake_minimum_required(VERSION 3.5)

project(Oblig2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Oblig2 main.cpp
    oblig2_mbb.h oblig2_mbb.cpp)

include(GNUInstallDirs)
install(TARGETS Oblig2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
