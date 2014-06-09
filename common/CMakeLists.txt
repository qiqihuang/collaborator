include_directories(/usr/local/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/common LIB_SRC)

add_library(common SHARED ${LIB_SRC})
