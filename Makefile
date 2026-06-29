# Nome del target
TARGET = engine.exe
# Compilatore
CXX = clang++
# Flag di ottimizzazione spinta
CXXFLAGS = -O3 -march=native -Wall

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)