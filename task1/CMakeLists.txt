cmake_minimum_required(VERSION 3.10)
project(MaxValueFinder)

set(CMAKE_C_STANDARD 99)

# Заголовочные файлы
include_directories(inc)

# Основная программа для задачи 1
add_executable(task1_program src/main.c src/fMax.c)
target_compile_definitions(task1_program PRIVATE TASK1=1)

# Основная программа для задачи 2
add_executable(task2_program src/main.c src/fMax.c)
target_compile_definitions(task2_program PRIVATE TASK2=1)

# Программа для самотестирования (тесты для задачи 1 и 2)
add_executable(test_suite src/main.c src/fMax.c)
target_compile_definitions(test_suite PRIVATE SELFTEST=1 TASK1=1 TASK2=1)
