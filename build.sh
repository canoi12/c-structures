CC=gcc
SOURCES=main.c
OUT=program

$($CC $SOURCES -o $OUT)

echo "Build successful.."