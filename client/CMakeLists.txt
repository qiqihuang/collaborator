include_directories(${PROJECT_SOURCE_DIR}/gen-cpp)
include_directories(${PROJECT_SOURCE_DIR}/common)
include_directories(/usr/local/include)
include_directories(/usr/include/jsoncpp)

aux_source_directory(${PROJECT_SOURCE_DIR}/client EXE_SRC)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(client ${EXE_SRC})

target_link_libraries(client common gen-cpp thrift)
