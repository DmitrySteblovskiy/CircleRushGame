cmake_minimum_required(VERSION 3.23)
project(CircleRush_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CircleRush_master
        CircleRush.sln
        DeathSquare.h
        Engine.cpp
        Engine.h
        Game.cpp
        GameTemplate.vcxproj
        GameTemplate.vcxproj.filters
        Graph.cpp
        Graph.h
        PlayerCircles.h
        PointSquare.h
        Square.h
        SquareManager.h)
