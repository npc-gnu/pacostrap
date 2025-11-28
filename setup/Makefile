# LICENSE is GPLv3

CXX = g++
cCXX = clang++
CXXFLAGS = -Imain/include -Ifunctions/include
OFLAGS = -march=native -flto # Optimisation flags

TARGET = pacostrap
SRC = $(wildcard main/src/*.cpp) $(wildcard functions/src/*.cpp)
OBJ = $(SRC:.cpp=.o)

build = $(CXX) $(OBJ) -o $(TARGET)
cbuild = $(cCXX) $(OBJ) -o $(TARGET)

fastflags = -O2 $(OFLAGS)
fasterflags = -O3 $(OFLAGS) -funroll-loops
fastestflags = -Ofast $(OFLAGS) -funroll-loops

$(TARGET): $(OBJ)
	$(build)
fast: $(OBJ)
	$(build) $(fastflags)
faster: $(OBJ) 
	$(build) $(fasterflags) 
fastest: $(OBJ) 
	$(build) $(fastestflags)

clang: $(OBJ)
	$(cbuild)
cfast: $(OBJ)
	$(cbuild) $(fastflags)
cfaster: $(OBJ)
	$(cbuild) $(fasterflags)
cfastest: $(OBJ)
	$(cbuild) $(fastestflags)

clean:
	rm -f $(OBJ) $(TARGET)
