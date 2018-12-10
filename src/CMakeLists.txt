cmake_minimum_required (VERSION 3.12)
project (pidigits)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-ffast-math ${CMAKE_CXX_FLAGS_RELEASE}")
find_package(OpenMP REQUIRED)

# pidigits
add_executable(pidigits main.cpp)
target_link_libraries(pidigits OpenMP::OpenMP_CXX)

# tests
find_package(GTest REQUIRED)
add_executable(pidigits_test main.t.cpp)
target_link_libraries(pidigits_test ${GTEST_BOTH_LIBRARIES} OpenMP::OpenMP_CXX)

# benchmarks
add_executable(pidigits_benchmark main.b.cpp)
target_link_libraries(pidigits_benchmark benchmark OpenMP::OpenMP_CXX)

