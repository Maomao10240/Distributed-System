cmake_minimum_required(VERSION 3.15)

# Set the project name and version
project(GrpcProtobufTest VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_PREFIX_PATH "/usr/local/opt/protobuf;/usr/local/opt/grpc")



# Find Protobuf package
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})

# Find gRPC package
find_package(gRPC REQUIRED)
include_directories(${gRPC_INCLUDE_DIRS})

# Source files
set(PROTO_FILES src/service.proto)
set(SRC_FILES src/client.cpp)

# Generate C++ source files from proto files
protobuf_generate_cpp(PROTO_SRC PROTO_HDRS ${PROTO_FILES})
grpc_generate_cpp(GRPC_SRC GRPC_HDRS ${PROTO_FILES})

# Add executable target
add_executable(GrpcProtobufTest ${SRC_FILES} ${PROTO_SRC} ${GRPC_SRC})

# Link libraries
target_link_libraries(GrpcProtobufTest ${Protobuf_LIBRARIES} gRPC::grpc++ gRPC::grpc)
