cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MyGRPCProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the path to Protobuf and gRPC includes and libraries
include_directories(/opt/miniconda3/include)
link_directories(/opt/miniconda3/lib)

# Specify the source files
set(SOURCE_FILES_CLIENT
    src/client.cpp
    src/utils/clienthelper.cpp
    src/protoSrc/service.pb.cc
    src/protoSrc/service.grpc.pb.cc
)

set(SOURCE_FILES_SERVER
    src/server.cpp
    src/utils/serverhelper.cpp
    src/protoSrc/service.pb.cc
    src/protoSrc/service.grpc.pb.cc
)

# Add executable target
add_executable(client ${SOURCE_FILES_CLIENT})
add_executable(server ${SOURCE_FILES_SERVER})

# Link libraries
target_link_libraries(client protobuf grpc++ grpc pthread)
target_link_libraries(server protobuf grpc++ grpc pthread)


# Specify the path to Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_FILES
    tests/test1.cpp
    # src/utils/serverhelper.cpp
    # src/protoSrc/service.pb.cc
    # src/protoSrc/service.grpc.pb.cc
)

# Add executable target
add_executable(runtest ${TEST_FILES})

# Link libraries
target_link_libraries(runtest GTest::gtest GTest::gtest_main pthread)

# target_link_libraries(runtest ${GTEST_LIBRARIES} pthread)

# Print GTest configuration
message(STATUS "GTest include dirs: ${GTEST_INCLUDE_DIRS}")
message(STATUS "GTest libraries: ${GTEST_LIBRARIES}")

# Enable testing
enable_testing()

# Add test cases
add_test(NAME runtest COMMAND runtest)