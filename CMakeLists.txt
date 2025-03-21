# Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE "Debug" )

# Nome do projeto
project(simple_compiler)

# Define a versão do padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona os diretórios de include
include_directories(${PROJECT_SOURCE_DIR}/includes)

# Adiciona os arquivos fonte
set(SOURCES
    src/main.cpp
    src/frontend/lexer/lexer.cpp
    src/frontend/lexer/tokenize.cpp
    src/frontend/parser/parser.cpp
    src/frontend/parser/ast.cpp

    src/frontend/parser/declarations/parse_class_declaration.cpp

    src/frontend/core/core.cpp
)

# Cria o executável
add_executable(scomp ${SOURCES})

# Se necessário, pode adicionar mais flags aqui (ex: -Wall)
# target_compile_options(neovim-clone PRIVATE -Wall)
