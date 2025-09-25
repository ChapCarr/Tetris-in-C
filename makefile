# Makefile for Tetris with raylib

CC = gcc
SRC = main.c shapes.c
OUT = run

# Default flags
CFLAGS = -std=c99 -Wall -Wextra -O2

# Platform detection
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)  # macOS
    # Homebrew installs raylib into /usr/local or /opt/homebrew
    RAYLIB_PATH := $(shell brew --prefix raylib)
    CFLAGS += -I$(RAYLIB_PATH)/include
    LDFLAGS = -L$(RAYLIB_PATH)/lib -lraylib \
              -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL
else  # Linux
    LDFLAGS = -lraylib -lm -ldl -lpthread -lGL -lX11
endif

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
