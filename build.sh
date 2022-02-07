#!/bin/bash

os=`uname`
ext='-lGL'
if [ $os == 'Darwin' ]
then
    ext='-framework OpenGL'
fi
cc -Wall main.c draw.c init.c file.c exts.c object.c -lSDL2 $ext
