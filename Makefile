# Makefile for simple Eigen3 flight dynamics example
#
# Compiler and flags
CXX      := clang++
CXXFLAGS := -std=c++17 -O2 -Wall -I/usr/include/eigen3

# Default Eigen path (can be overridden)
EIGEN_PATH ?= /usr/include/eigen3
CXXFLAGS  += -I$(EIGEN_PATH)

# Target and sources
TARGET   := flight
SRC      := flight.cc
OBJ      := $(SRC:.cc=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

