cmake_minimum_required(VERSION 3.5)

project(Satellitt-labz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Satellitt-labz main.cpp
    tempwatch.h tempwatch.cpp)

include(GNUInstallDirs)
install(TARGETS Satellitt-labz
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
