# This is a Makefile

# The compiler
CXX = g++

# Compiler flags (optional)
CXXFLAGS = -Wall -g

# The target executable
TARGET = hello

# How to build the executable
$(TARGET): hello.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) hello.o

# How to build the object file
hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -c hello.cpp

# How to clean up (optional)
clean:
	rm -f $(TARGET) *.o