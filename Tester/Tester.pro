#-------------------------------------------------
#
# Project created by QtCreator 2009-10-08T23:01:43
#
#-------------------------------------------------

QT       -= core gui

TARGET = Tester
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -L../API -L../API/debug \
	-lLBAPI

unix:LIBS += -ldl

SOURCES += main.cpp

QMAKE_EXTRA_TARGETS += plugintarget
POST_TARGETDEPS += .plugins
plugintarget.target = .plugins
win32:plugintarget.commands = CopyPlugins.bat
unix:plugintarget.commands = ./CopyPlugins.sh
