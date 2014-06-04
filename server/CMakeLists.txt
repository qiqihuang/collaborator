include_directories(${PROJECT_SOURCE_DIR}/gen-cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/local/include)
include_directories(/usr/include/jsoncpp)

link_directories(${PROJECT_SOURCE_DIR}/gen-cpp)
link_directories(${PROJECT_SOURCE_DIR}/lib)

aux_source_directory(${PROJECT_SOURCE_DIR}/server EXE_SRC)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_DEFINITIONS(-D_DEBUG)

add_executable(server ${EXE_SRC})

target_link_libraries(server common thrift diff_match_patch jsoncpp)
