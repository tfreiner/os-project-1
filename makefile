CC=gcc
CFLAGS=-Wall
TARGET=program1 program2 program3 program4 program5 program6

all: $(TARGET) 

$(TARGET): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o $(TARGET)
