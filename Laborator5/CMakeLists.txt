cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(Laborator5)

set(SOURCE_FILES
        src/domain/Film.cpp
        src/domain/Film.h
        src/repository/FilmRepository.h
        src/repository/FilmRepository.cpp
        src/controller/FilmController.h
        src/controller/FilmController.cpp
        src/ui/UI.h
        src/ui/UI.cpp
        main.cpp)

add_executable(Laborator_5_run ${SOURCE_FILES})

add_subdirectory(test)