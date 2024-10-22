# Variables
CXX = g++
CXXFLAGS = -I C:/SFML/SFML-2.6.1/include -std=c++17
LDFLAGS = -L C:/SFML/SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET = game
SRC = main.cpp

# Rule to build the target
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# Rule to clean the build
clean:
	del $(TARGET)
