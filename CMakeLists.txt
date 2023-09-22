cmake_minimum_required(VERSION 3.26)
project(CAD)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cc
        BaseClass/figure.cc
        BaseClass/figure.h
        BaseClass/coordinates.h
        Figures/Circle/circle.cc
        Figures/Circle/circle.h
        Figures/Ellips/ellips.cc
        Figures/Ellips/ellips.h
        Figures/Helix/helix.cc
        Figures/Helix/helix.h
        Randomazer/randomazer.h
        Randomazer/randomazer.cc
        main.cc)
