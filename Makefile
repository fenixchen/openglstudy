CC=gcc
CXX=g++
LIBS=-lGL -lglut
CFLAGS=-I/usr/include/X11R6 -Wall -g3 -O0
DIR_OBJ=obj
DIR_OUT=out

CSRCS=$(wildcard *.c)
CXXSRCS=$(wildcard *.cpp)

OBJS=$(patsubst %.c, $(DIR_OBJ)/%.o, $(CSRCS))
OBJS+=$(patsubst %.cpp, $(DIR_OBJ)/%.o, $(CXXSRCS))


$(DIR_OBJ)/%.o: %.cpp	
	@mkdir -p $(dir $@)
	$(CXX) -o $@ -c $< $(CFLAGS)
 
OUTPUT=test1 test2

PROGS=$(addprefix $(DIR_OUT)/,$(OUTPUT))
all:$(PROGS)

$(DIR_OUT)/test1:$(DIR_OBJ)/test1.o
	@mkdir -p ${DIR_OUT}
	$(CXX) -o $@ $< $(LIBS)		
	
$(DIR_OUT)/test2:$(DIR_OBJ)/test2.o
	@mkdir -p ${DIR_OUT}
	$(CXX) -o $@ $< $(LIBS)	

clean:
	@rm -f $PROGS $(OBJS) 	