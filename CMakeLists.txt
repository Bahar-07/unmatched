cmake_minimum_required(VERSION 4.2.0)

project(Unmatched)

add_subdirectory(raylib)

add_executable(app
    main.cpp

    game.cpp

    map.cpp
    

    space.cpp
    

    character.cpp
    

    card.cpp
    

    ui.cpp

)
target_link_libraries(app PRIVATE raylib)