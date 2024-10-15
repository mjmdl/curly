#!/bin/sh

CC="gcc"
CFLAGS="-Wall -Wextra -Wpedantic -Werror
        -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter
        -Iinclude
        `pkg-config --cflags gtk4`"
LFLAGS="`pkg-config --libs gtk4`"
SOURCES="./source/main.c ./source/app.c ./source/appwindow.c"
TARGET="curly"

$CC $CFLAGS -o $TARGET $SOURCES $LFLAGS
