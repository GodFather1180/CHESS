# Variables
CXX = g++
CXXFLAGS = -I./src/include -std=c++17
LDFLAGS = -L./src/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lgdi32
TARGET = game

# Build target
all: $(TARGET)

$(TARGET): main.cpp board.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp board.cpp $(LDFLAGS)

# Clean up by deleting the executable and object files
clean:
	del $(TARGET).exe
	del *.o

# For convenience, clean and rebuild
rebuild: clean all
