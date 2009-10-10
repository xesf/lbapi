# -------------------------------------------------
# Project created by QtCreator 2009-08-26T17:18:25
# -------------------------------------------------
QT -= core \
    gui
TARGET = LBAPI
TEMPLATE = lib
CONFIG += staticlib
SOURCES += PackagingServer/PackagingServer.cpp \
    GraphicsServer/GraphicsServer.cpp \
    SoundServer/SoundServer.cpp \
    GameplayServer/GameplayServer.cpp \
    Core/implementation/PluginLoader.cpp \
    Core/Core.cpp
HEADERS += PackagingServer/PackagingServer.h \
    GraphicsServer/GraphicsServer.h \
    SoundServer/SoundServer.h \
    GameplayServer/GameplayServer.h \
    Core/implementation/PluginLoader.h \
    Core/Core.h
