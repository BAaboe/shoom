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
CS=./src/client
SS=./src/server

# not too sophisticated dependency
SOBJ=				\

COBJ=				\

all:	 $(O)/server $(O)/client

server:  $(O)/server

clean:
	rm -f ./build/*.o

run: all
	./main


$(O)/server:	$(SOBJ) $(O)/server/server.o
	$(CC) $(CFLAGS) $(OBJS) $(O)/server/server.o \
	-o server $(LIBS)

$(O)/client:	$(COBJ) $(O)/client/client.o
	$(CC) $(CFLAGS) $(OBJS) $(O)/client/client.o \
	-o client $(LIBS)

$(O)/client/%.o:	$(CS)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


$(O)/server/%.o:	$(SS)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#############################################################
#
#############################################################
