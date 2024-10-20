# Variables 
Css = g++
CssFLAGS = -I C:/SFML/SFML-2.6.1/include -std=c++17
LDFLAGS = -L C:/SFML/SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
TARGET = Game
SRC = main.cpp

# Rule to build the target
$(TARGET): $(SRC)
	$(Css) $(SRC) -o $(TARGET) $(CssFLAGS) $(LDFLAGS)

# Rule to clean the build
clean:
	del $(TARGET)
