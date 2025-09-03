cmake_minimum_required(VERSION 3.20)
project(MeuJogo)

set(CMAKE_CXX_STANDARD 17)

# Encontra as bibliotecas SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Adiciona os diretórios de inclusão (headers)
include_directories(include)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_MIXER_INCLUDE_DIRS})

# Adiciona o executável e os arquivos-fonte
add_executable(MeuJogo src/SDL.cpp
        include/Game.h
        include/SDL_include.h
        include/State.h
        src/Game.cpp
        src/main.cpp
        src/State.cpp)

# Linka as bibliotecas SDL2 com o seu executável
target_link_libraries(MeuJogo ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES})