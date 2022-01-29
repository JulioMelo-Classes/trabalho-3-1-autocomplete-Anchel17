cmake_minimum_required(VERSION 3.0)

### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "autocomplete"
add_executable( autocomplete
                src/main.cpp
                src/process.cpp
                src/interface.cpp
                src/database.cpp)
