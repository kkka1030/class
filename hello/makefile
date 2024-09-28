CC = gcc


CXXFLAGS = -std=c++11 -Wall


TARGET = hello


SRC = hello.cpp

all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(SRC) -lstdc++


clean:
	rm -f $(TARGET)
