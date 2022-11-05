CC = g++
CFLAGS = -g
TARGET = main.out
OBJS = main.o doublelinked_list.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.cpp
conversion.o : doublelinked_list.cpp

clean :
	rm -f *.o main.out