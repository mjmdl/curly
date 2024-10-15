#!/bin/sh

CC="gcc"
CFLAGS="-Wall -Wextra -Wpedantic -Werror
        -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter
        -Iinclude
        `pkg-config --cflags gtk4`
        `pkg-config --cflags libcurl`"
LFLAGS="`pkg-config --libs gtk4`
        `pkg-config --libs libcurl`"
SOURCES="./source/main.c ./source/app.c ./source/appwindow.c ./source/reqinput.c"
TARGET="curly"

$CC $CFLAGS -o $TARGET $SOURCES $LFLAGS
