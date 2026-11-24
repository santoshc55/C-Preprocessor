
CC = gcc
CFLAGS = -Wall

TARGET = mypreprocessor

SRC = main.c comment_removal.c file_inclusion.c macro_handler.c

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c preprocessor.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) *.i

