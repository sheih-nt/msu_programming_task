cmake_minimum_required(VERSION 3.10)
project(PressureCheck)

set(CMAKE_C_STANDARD 99)

# Заголовочные файлы
include_directories(inc)

# Основная программа
add_executable(pressure_program src/main.c src/PressureCheck.c)
target_compile_definitions(pressure_program PRIVATE TASK1=1)

# Программа для тестирования
add_executable(test_suite src/main.c src/PressureCheck.c)
target_compile_definitions(test_suite PRIVATE SELFTEST=1 TASK1=1)

if(NOT MSVC)
    target_compile_options(test_suite PRIVATE -g --coverage)
    target_link_libraries(test_suite PRIVATE gcov)
endif()

file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_normal.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_empty.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_invalid.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_critical.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
