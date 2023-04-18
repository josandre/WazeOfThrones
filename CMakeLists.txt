cmake_minimum_required(VERSION 3.24)
project(WazeOfThrones)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(dependencies)

add_executable(WazeOfThrones main.cpp core/source/ui/SfmlApp.cpp core/header/ui/SfmlApp.h core/source/City.cpp core/header/City.h core/source/Route.cpp core/header/Route.h core/source/Map.cpp core/header/Map.h core/source/Hash.cpp core/header/Hash.h core/header/MapDAO.cpp core/source/MapDAO.h)
target_link_libraries(WazeOfThrones PRIVATE sfml-system sfml-window sfml-graphics)
target_link_libraries(WazeOfThrones PRIVATE ImGui-SFML::ImGui-SFML)