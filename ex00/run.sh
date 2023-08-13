#! /usr/bin/bash

set -o xtrace

CC='cc'
CFLAGS='-Wall -Wextra -Werror -g3'
EXEC='rush-01'

$CC $CFLAGS -o $EXEC *.c

./$EXEC "$1"
