# 1. Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# 2. Nome do projeto
project(MeuProjetoOpenGL)

# 3. Define C++11 ou superior
set(CMAKE_CXX_STANDARD 11)

# 4. Encontra o pacote OpenGL
find_package(OpenGL REQUIRED)

# 5. Encontra a biblioteca GLFW (requer GLFW instalado)
find_package(glfw3 REQUIRED)

# 6. Adiciona seu executável
add_executable(meu_app main.cpp glad.c) # glad.c é essencial

# 7. Vincula as bibliotecas
target_link_libraries(meu_app
    PRIVATE
    glfw
    OpenGL::GL
)

