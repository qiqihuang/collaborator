include_directories(/usr/local/include)
include_directories(/usr/share/qt4/mkspecs/linux-g++-64)
include_directories(/usr/include/qt4/QtCore)
include_directories(/usr/include/qt4/QtGui)
include_directories(/usr/include/qt4)

aux_source_directory(${PROJECT_SOURCE_DIR}/diff_match_patch_20121119/cpp LIB_SRC)

add_library(diff_match_patch SHARED ${LIB_SRC})
