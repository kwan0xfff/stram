# Makefile for simple Eigen3 flight dynamics example
#

# Default Eigen path (can be overridden)
EIGEN_PATH ?= /usr/include/eigen3

# Compiler and flags
CXX      := clang++
CXXFLAGS := -std=c++17 -O2 -Wall -I$(EIGEN_PATH)

# Target and sources
TARGET   := flight
SRC      := flight.cc vectoroutput.cc
OBJ      := $(SRC:.cc=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

vectoroutput.o : vectoroutput.hh
flight.o : vectoroutput.hh

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

