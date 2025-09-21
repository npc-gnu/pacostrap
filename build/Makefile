CXX = g++
CXXFLAGS = -I../Arch_iso_edition/include -I../functions/include

TARGET = pacostrap
SRC = $(wildcard ../Arch_iso_edition/src/*.cpp) $(wildcard ../functions/src/*.cpp)
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
