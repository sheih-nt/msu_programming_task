cmake_minimum_required(VERSION 3.10)
project(MaxValueFinder)

set(CMAKE_C_STANDARD 99)

# Указание директории заголовочных файлов
include_directories(inc)

# Основная программа для задачи 1
add_executable(task1_program src/main.c src/MaxValueFinder.c)
target_compile_definitions(task1_program PRIVATE TASK1=1)

# Программа для тестирования
add_executable(test_suite src/main.c src/MaxValueFinder.c)
target_compile_definitions(test_suite PRIVATE SELFTEST=1 TASK1=1)

# Опции компиляции и линковки для покрытия кода
# Используйте -g для отладки
target_compile_options(test_suite PRIVATE -g)
target_link_libraries(test_suite PRIVATE gcov)

# Копирование тестовых файлов в директорию сборки
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test1.txt DESTINATION ${CMAKE_BINARY_DIR}/test)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test2.txt DESTINATION ${CMAKE_BINARY_DIR}/test)
file(COPY ${CMAKE_SOURCE_DIR}/test/task_empty_file/test_empty.txt DESTINATION ${CMAKE_BINARY_DIR}/test)
file(COPY ${CMAKE_SOURCE_DIR}/test/task_invalid_syntax/test_invalid.txt DESTINATION ${CMAKE_BINARY_DIR}/test)
file(COPY ${CMAKE_SOURCE_DIR}/test/task_float_edge_cases/test_float_edge_cases.txt DESTINATION ${CMAKE_BINARY_DIR}/test)  # добавьте это
