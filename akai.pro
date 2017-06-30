TEMPLATE = app
TARGET = akai
INCLUDEPATH += .
#RC_ICONS += icons/akai.svg

# Input
HEADERS += audio.h
SOURCES += audio.cpp \
           main.cpp
QMAKE_CXXFLAGS += -g
LIBS += -lQt5Widgets -lQt5Network -lQt5Multimedia
OBJECTS_DIR=objects
MOC_DIR=objects

unix:application.path = ~/.local/share/akai
unix:application.files = Akai

INSTALLS += application
