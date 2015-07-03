CC=gcc
CXX=g++
LIBS=-lGL -lglut
CFLAGS=-I/usr/include/X11R6

all: test1

test1: test1.cpp
	$(CXX) -o $@ $< $(LIBS)		
