CXX = g++
CXXFLAGS = -IArch_iso_edition/include -Ifunctions/include

TARGET = pacostrap
SRC = $(wildcard Arch_iso_edition/src/*.cpp) $(wildcard functions/src/*.cpp)
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
