APP := tetris
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

CC := cc
CFLAGS := -std=c11 -O2 -Wall -Wextra
LDLIBS := -lraylib -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL

all: $(APP)

$(APP): $(OBJ)
	$(CC) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(APP)
	./$(APP)

clean:
	rm -f $(OBJ) $(APP)
