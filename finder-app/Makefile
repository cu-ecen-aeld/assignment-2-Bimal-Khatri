# Makefile

CC := gcc
CFLAGS := -Wall -Wextra -std=c99

# Check if CROSS_COMPILE is specified
ifdef CROSS_COMPILE
    CC := $(CROSS_COMPILE)gcc
    
endif

SRCS := writer.c
OBJS := $(SRCS:.c=.o)
TARGET := writer

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

