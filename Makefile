################################################################
#
# $Id:$
#
# $Log:$
#
CC=  g++  # gcc or g++

CFLAGS=-g -Wall -L/usr/X11R6/lib -lX11# -DUSEASM 

# subdirectory for objects
O=./build
S=./src

# not too sophisticated dependency
OBJS=				\

all:	 $(O)/main

clean:
	rm -f ./build/*.o

run: all
	./main

$(O)/main:	$(OBJS) $(O)/main.o
	$(CC) $(CFLAGS) $(OBJS) $(O)/main.o \
	-o main $(LIBS)

$(O)/%.o:	$(S)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#############################################################
#
#############################################################
