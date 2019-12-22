# -*- MakeFile -*-
# made by simon pikalov 


#variabeles 
CC=gcc
AR=ar
OBJECTS_ISORT=mainSort.o
OBJECTS_TXTFIND=mainTxt.o
OBJECTS_LIB_SORT=hw3.o
OBJECTS_LIB_TXT=txtfind.o
FLAGS= -Wall -g


#mak all the programs
all: libsort libtxt txtfind isort

# static library sort
libsort: $(OBJECTS_LIB_SORT)
	$(AR) -rcs libsort.a $(OBJECTS_LIB_SORT)

# static library txt
libtxt: $(OBJECTS_LIB_TXT)
	$(AR) -rcs libtxt.a $(OBJECTS_LIB_TXT)

#main linked to static lib
isort: $(OBJECTS_ISORT) libsort
	$(CC) $(FLAGS) -o isort $(OBJECTS_ISORT) libsort.a

#main linked to static libs
txtfind: $(OBJECTS_TXTFIND) libtxt
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_TXTFIND) libtxt.a

mainTxt.o: mainTxt.c hw3.h
	$(CC) $(FLAGS) -c mainTxt.c

mainSort.o: mainSort.c hw3.h
	$(CC) $(FLAGS) -c mainSort.c

hw3.o: hw3.c hw3.h
	$(CC) $(FLAGS) -fPIC -c hw3.c

txtfind.o: txtfind.c hw3.h
	$(CC) $(FLAGS) -fPIC -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so isort txtfind

