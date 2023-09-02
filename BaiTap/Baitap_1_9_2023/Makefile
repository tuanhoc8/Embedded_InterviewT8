CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -std=c17 -IHeader
CXXFLAGS := -Wall -Wextra -std=c++17 -IHeader
TARGET := main

SRC_C := $(wildcard Source/*.c)
SRC_CPP := $(wildcard Source/*.cpp)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC_C) $(SRC_CPP)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)