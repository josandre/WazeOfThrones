cmake_minimum_required(VERSION 3.24)
project(WazeOfThrones)

set(CMAKE_CXX_STANDARD 17)

add_executable(WazeOfThrones main.cpp core/source/ui/SfmlApp.cpp core/header/ui/SfmlApp.h core/source/City.cpp core/header/City.h core/source/Route.cpp core/header/Route.h core/source/Map.cpp core/header/Map.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(WazeOfThrones sfml-system sfml-window sfml-graphics)