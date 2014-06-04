#QT += sql xml network
TEMPLATE = lib
#CONFIG += qt debug_and_release
CONFIG += staticlib

# don't embed the manifest for now (doesn't work :( )
#CONFIG -= embed_manifest_exe 

FORMS =

HEADERS = diff_match_patch.h

SOURCES = diff_match_patch.cpp

RESOURCES = 

