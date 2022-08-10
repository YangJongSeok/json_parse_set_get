# Makefile
CC = gcc
CFLAGS = -g -Wall
LDFLAGS =  
OBJECTS = json.o
TARGET = json
LIBPATH = /Users/jongseok/Desktop/VScode/lib
LIBS = json

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -I$(LIBPATH)/$(LIBS) -L$(LIBPATH) -l$(LIBS) -o $(TARGET) $(OBJECTS)

$(OBJECTS) : json.c
	$(CC) -I$(LIBPATH)/$(LIBS) -c json.c

clean:
	rm -f *.o
	rm -f $(TARGET)
#	rm -f *.json
