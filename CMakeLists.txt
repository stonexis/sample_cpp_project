cmake_minimum_required(VERSION 3.14)

project(sample_cpp_project)

set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
# Укажите стандарт C++
add_executable(main main.cpp my_add.cpp)
include(FetchContent)
FetchContent_Declare(
    googleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests test_add.cpp my_add.cpp)
target_link_libraries(tests gtest_main)

include(FetchContent)
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.7.1  # Убедитесь, что используете последнюю стабильную версию
)
FetchContent_MakeAvailable(benchmark)
add_executable(benchmark_tests benchmark_tests.cpp my_add.cpp)
target_link_libraries(benchmark_tests benchmark::benchmark)

include(GoogleTest)
gtest_discover_tests(tests)
