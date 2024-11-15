cmake_minimum_required(VERSION 3.10)
project(CombinedTasks)

set(CMAKE_C_STANDARD 99)

# Указание директории заголовочных файлов
include_directories(inc)

# Имена для программ
set(APPNAME_TASK1 task1_program)
set(APPNAME_TASK1_SELFTEST task1_test_suite)
set(APPNAME_TASK2 task2_program)
set(APPNAME_TASK2_SELFTEST task2_test_suite)

# Компиляция программы для задачи 1
add_executable(${APPNAME_TASK1} src/main.c src/MaxFinderValue.c)
target_compile_definitions(${APPNAME_TASK1} PRIVATE -DTASK1)

# Тесты для задачи 1
add_executable(${APPNAME_TASK1_SELFTEST} src/main.c src/MaxFinderValue.c)
target_compile_definitions(${APPNAME_TASK1_SELFTEST} PRIVATE -DTASK1 -DSELFTEST)

# Компиляция программы для задачи 2
add_executable(${APPNAME_TASK2} src/main.c src/PressureCheck.c)
target_compile_definitions(${APPNAME_TASK2} PRIVATE -DTASK2)

# Тесты для задачи 2
add_executable(${APPNAME_TASK2_SELFTEST} src/main.c src/PressureCheck.c)
target_compile_definitions(${APPNAME_TASK2_SELFTEST} PRIVATE -DTASK2 -DSELFTEST)

# Опции компиляции и линковки для покрытия кода (только для тестов)
if(NOT MSVC)
    target_compile_options(${APPNAME_TASK1_SELFTEST} PRIVATE -g --coverage)
    target_link_libraries(${APPNAME_TASK1_SELFTEST} PRIVATE gcov)

    target_compile_options(${APPNAME_TASK2_SELFTEST} PRIVATE -g --coverage)
    target_link_libraries(${APPNAME_TASK2_SELFTEST} PRIVATE gcov)
endif()

# Копирование тестовых файлов для задачи 1
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test1.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test2a.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_empty.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_invalid.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/test_float_edge_cases.txt DESTINATION ${CMAKE_BINARY_DIR}/test)

# Копирование тестовых файлов для задачи 2
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_normal.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_empty.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_invalid.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
file(COPY ${CMAKE_SOURCE_DIR}/test/global/test_critical.txt DESTINATION ${CMAKE_BINARY_DIR}/test/global)
