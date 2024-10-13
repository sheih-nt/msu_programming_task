# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Указываем название проекта
project(MaxValueFinder)

# Указываем стандарт языка C
set(CMAKE_C_STANDARD 99)

# Указываем пути к заголовочным файлам
include_directories(inc)

# Указываем, какие файлы будут частью проекта
set(SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/fMax.c"
)


# Создание исполняемого файла
add_executable(MaxValueFinder ${SOURCES})
