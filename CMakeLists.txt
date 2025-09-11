# Versão mínima do CMake e nome do projeto
cmake_minimum_required(VERSION 3.10)
project(MeuJogo CXX)

# Define o padrão do C++ para C++11, como exigido pela disciplina
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Configuração do Projeto ---

# Encontra automaticamente todos os ficheiros .cpp dentro da pasta 'src'
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Cria o executável final com o nome "MeuJogo" a partir dos ficheiros fonte encontrados
add_executable(MeuJogo ${SOURCES}
        include/State.h
        src/State.cpp
        include/Sprite.h
        include/Music.h
        src/Sprite.cpp
        src/Music.cpp
        include/Vec2.h
        src/Vec2.cpp
        include/Rect.h)

# --- Inclusão e Linkagem (MÉTODO TOTALMENTE MANUAL PARA MAC) ---
# Esta abordagem ignora o find_package, que está a falhar, e usa os caminhos exatos do Homebrew.

# Adiciona os diretórios de include necessários
target_include_directories(MeuJogo PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"  # Para os seus cabeçalhos (.h)
        "/opt/homebrew/include"               # Para os cabeçalhos da SDL
)

# Adiciona o diretório onde o linker deve procurar as bibliotecas
target_link_directories(MeuJogo PUBLIC
        "/opt/homebrew/lib"                   # Para as bibliotecas da SDL (.dylib)
)

# Linka as bibliotecas da SDL pelo nome
target_link_libraries(MeuJogo PUBLIC
        SDL2
        SDL2_image
        SDL2_mixer
        SDL2_ttf
)

# --- Passo Pós-Compilação: Copiar Recursos ---
# Copia a pasta "Recursos" para o mesmo diretório do executável
add_custom_command(TARGET MeuJogo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Recursos
        $<TARGET_FILE_DIR:MeuJogo>/Recursos
)

