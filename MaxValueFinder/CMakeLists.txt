cmake_minimum_required(VERSION 3.10)
project(MaxFinderValue)

set(CMAKE_C_STANDARD 99)

# Указание директории заголовочных файлов
include_directories(inc)

# Основная программа для задачи 1
add_executable(task1_program src/main.c src/MaxFinderValue.c)
target_compile_definitions(task1_program PRIVATE TASK1=1)

# Программа для тестирования
add_executable(test_suite src/main.c src/MaxFinderValue.c)
target_compile_definitions(test_suite PRIVATE SELFTEST=1 TASK1=1)

# Опции компиляции и линковки для покрытия кода
if(MSVC)
else()
target_compile_options(test_suite PRIVATE -g --coverage)
target_link_libraries(test_suite PRIVATE gcov)
endif()

# Копирование тестовых файлов в директорию сборки
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test1.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test2a.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_empty.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_invalid.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/test_float_edge_cases.txt DESTINATION ${CMAKE_BINARY_DIR}/test)
