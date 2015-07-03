CC=gcc
CXX=g++
LIBS=-lGL -lglut
CFLAGS=-I/usr/include/X11R6
DIR_OBJ=obj
DIR_OUT=out

CSRCS=$(wildcard *.c)
CXXSRCS=$(wildcard *.cpp)

OBJS=$(patsubst %.c, $(DIR_OBJ)/%.o, $(CSRCS))
OBJS+=$(patsubst %.cpp, $(DIR_OBJ)/%.o, $(CXXSRCS))


$(DIR_OBJ)/%.o: %.cpp	
	@mkdir -p $(dir $@)
	$(CXX) -o $@ -c $< $(CFLAGS)
 
PROGS=test1

all:$(PROGS)

test1: $(DIR_OBJ)/test1.o
	@mkdir -p ${DIR_OUT}
	$(CXX) -o ${DIR_OUT}/$@ $< $(LIBS)		

clean:
	@rm -f $PROGS $(OBJS) 	