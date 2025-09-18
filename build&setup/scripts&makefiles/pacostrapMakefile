# Derleyici ve bayraklar
CXX = g++
CXXFLAGS = -Imain/include -Ifunctions/include

# Çıktı dosyası
TARGET = pacostrap

# Kaynak dosyalar ve nesne dosyaları
SRC = $(wildcard main/src/*.cpp) $(wildcard functions/src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Varsayılan kural
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Temizlik
clean:
	rm -f $(OBJ) $(TARGET)


