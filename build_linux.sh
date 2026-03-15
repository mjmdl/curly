#!/bin/sh

CC="gcc"
CFLAGS="-std=gnu11 -Wall -Wextra -Wpedantic -Werror -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Isource `pkg-config --cflags gtk4` `pkg-config --cflags libcurl`"
LFLAGS="`pkg-config --libs gtk4` `pkg-config --libs libcurl`"
SOURCES="./source/curly_main.c ./source/curly_app.c ./source/curly_app_window.c ./source/curly_request_field.c ./source/curly_http_service.c"
TARGET="curly"

$CC $CFLAGS -o $TARGET $SOURCES $LFLAGS
