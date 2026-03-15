#!/bin/sh

CC="gcc"
CFLAGS="-std=gnu11 -Wall -Wextra -Wpedantic -Werror -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Isource `pkg-config --cflags gtk4`"
LFLAGS="`pkg-config --libs gtk4`"
SOURCES="./source/curly_main.c ./source/curly_app.c ./source/curly_app_window.c"
TARGET="curly"

$CC $CFLAGS -o $TARGET $SOURCES $LFLAGS
