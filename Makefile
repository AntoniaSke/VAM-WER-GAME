
CLFAGS = -Wall -g3
SOURCES = $(wildcard *.cpp)
TARGET= main
$(TARGET): $(SOURCES) 
	g++ $(CLFAGS) $(SOURCES) -o $(TARGET)
clean:
	rm -f main *.o