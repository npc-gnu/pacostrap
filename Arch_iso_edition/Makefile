CXX = g++
CXXFLAGS = -Iinclude -I../functions/include

TARGET = pacostrap
SRC = $(wildcard src/*.cpp) $(wildcard ../functions/src/*.cpp)
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET
