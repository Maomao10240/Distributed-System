cmake_minimum_required(VERSION 3.10)

project(DistributedSys)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(src)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link necessary libraries (if any, for example, SDL)


# Add the executable
add_executable(DistributedSys src/client.cpp src/server.cpp)

enable_testing()

# Specify the path to the Google Test libraries
#link_directories(/usr/local/opt/googletest/lib)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests tests/test1.cpp src/client.cpp src/server.cpp)
# target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTests GTest::GTest GTest::Main pthread)

add_test(NAME runTests COMMAND runTests)