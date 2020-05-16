#!/bin/bash


g++ -c -o imgGenObj.o imgGenObj.c -lcurl
g++ -c -o randImgInterface.o randImgInterface.c

g++ -o genRandImg imgGenObj.o randImgInterface.o -lcurl
