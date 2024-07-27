# Variables
PROTOC = protoc
GRPC_CPP_PLUGIN = $(shell which grpc_cpp_plugin)
PROTO_FILES = src/service.proto
CPP_SRC = src/client.cpp
CPP_OUT_DIR = src/protoSrc
GRPC_OUT_DIR = src/protoSrc


# Define the targets

client: $(PROTO_FILES) $(CPP_SRC)
	@echo "Generating C++ code from .proto files..."
	$(PROTOC) -I=src --cpp_out=$(CPP_OUT_DIR) --grpc_out=$(GRPC_OUT_DIR) --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN) $(PROTO_FILES)
	@echo "Compiling the client..."
	g++ -std=c++14 -o $(CPP_SRC) $(CPP_OUT_DIR)/*.cc $(GRPC_OUT_DIR)/*.cc -lprotobuf -lgrpc++ -lpthread

clean:
	rm -f $(CPP_OUT_DIR)/*.cc $(GRPC_OUT_DIR)/*.cc
