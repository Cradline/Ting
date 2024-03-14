cmake_minimum_required(VERSION 3.5)

project(Oblig LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Oblig main.cpp
    oblig_1_mbb.h oblig_1_mbb.cpp

)

include(GNUInstallDirs)
install(TARGETS Oblig
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
