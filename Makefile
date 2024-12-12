# define the compiler to use
CXX = g++
# define the compiler flags to use
CXXFLAGS = -Wall -Wextra -std=c++17
# define the target executable
TARGET = skip_list_app
# File to compile
SRC = main.cpp Skiplist.cpp
OBJS = $(SRCS:.cpp=.o)

# Header files
DEPS = Skiplist.h

# default target to build 
all: $(TARGET)

# target to build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# clean up generated files - remove target executable if exists 
clean:
	rm -f $(TARGET)

.PHONY: all clean