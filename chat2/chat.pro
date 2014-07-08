#-------------------------------------------------
#
# Project created by QtCreator 2010-06-02T08:59:18
#
#-------------------------------------------------
QT  += widgets
QT       += core gui
QT       += network
QT 	+= multimedia

TARGET = chat
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tcpclient.cpp \
    tcpserver.cpp \
    chat.cpp \
    login.cpp \
    callclient.cc \
    chatclient.cc \
    console.cc \
    talkmm.cc \
    Unit.cc \
    mainwindow.cpp \
    fileclient.cc

HEADERS  += widget.h \
    tcpclient.h \
    tcpserver.h \
    chat.h \
    login.h \
    callclient.h \
    chatclient.h \
    console.h \
    define.h \
    MVC.h \
    talkmm.h \
    Unit.h \
    mainwindow.h \
    fileclient.h

FORMS    += widget.ui \
    tcpclient.ui \
    tcpserver.ui \
    chat.ui \
    login.ui \
    mainwindow.ui


RESOURCES += \
    resource.qrc

OTHER_FILES += \
    icon.rc
RC_FILE += icon.rc

DEFINES += LINUX POSIX _SIGSLOT_HAS_POSIX_THREADS

CONFIG +=compile_libtooll
CONFIG +=link_pkgconfig
#PKGCONFIG +=

LIBS += /home/huang/workspace/XXPalk_V1/talk/login/.libs/libcricketlogin.a \
        /home/huang/workspace/XXPalk_V1/talk/session/phone/.libs/libcricketsessionphone.a \
        /home/huang/workspace/XXPalk_V1/talk/session/fileshare/.libs/libcricketsessionfileshare.a \
        /home/huang/workspace/XXPalk_V1/talk/session/tunnel/.libs/libcricketsessiontunnel.a \
        /home/huang/workspace/XXPalk_V1/talk/p2p/client/.libs/libcricketp2pclient.a \
        /home/huang/workspace/XXPalk_V1/talk/p2p/base/.libs/libcricketp2pbase.a \
        /home/huang/workspace/XXPalk_V1/talk/xmpp/.libs/libcricketxmpp.a \
        /home/huang/workspace/XXPalk_V1/talk/xmllite/.libs/libcricketxmllite.a \
        -lexpat -lortp -lpthread -lrt   -lpthread -lssl -lcrypto  -L/usr/local/lib -lilbc -lm -lspeex   -Wl,--export-dynamic -pthread -lgmodule-2.0 -lgthread-2.0 -lglib-2.0    -lmediastreamer_base -lmediastreamer_voip -lortp -lpthread -lrt

