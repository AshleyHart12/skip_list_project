CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = skip_list_app
SRC = main.cpp SkipList.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)