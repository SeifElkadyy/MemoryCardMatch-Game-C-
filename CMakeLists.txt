cmake_minimum_required(VERSION 3.29)
project(CS3_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS3_Project Card.cpp
        Card.h
        Deck.h
        Player.h
        Game.h
        main.cpp
        Deck.cpp
        Player.cpp
        Game.cpp
)
