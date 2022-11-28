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
SOBJ=				\

COBJ=				\

all:	 $(O)/main

server:  $(O)/server

clean:
	rm -f ./build/*.o

run: all
	./main


$(O)/server:	$(OBJS) $(O)/server.o
	$(CC) $(CFLAGS) $(OBJS) $(O)/server.o \
	-o server $(LIBS)

$(O)/main:	$(OBJS) $(O)/main.o
	$(CC) $(CFLAGS) $(OBJS) $(O)/main.o \
	-o main $(LIBS)

$(O)/%.o:	$(S)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#############################################################
#
#############################################################
