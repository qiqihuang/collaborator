include_directories(/usr/local/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/gen-cpp LIB_SRC)

add_library(common SHARED ${LIB_SRC})
