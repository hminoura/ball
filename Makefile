TARGET = main

SRCS   = $(TARGET).cpp App.cpp Timer.cpp Rand.cpp BallApp.cpp Ball.cpp
OBJS   = $(SRCS:%.cpp=%.o)
## for macOS (SFML: brew)
#CXX    = clang++
#CXXFLAGS = -std=c++11 -Wc++11-extensions -g

## for Linux (SfLinux
CXX    = c++
CXXFLAGS = -std=c++11 -g
LIBS     = -lsfml-graphics -lsfml-window -lsfml-system

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o  $@ $^ $(LDFLAGS) $(LIBS)
	strip $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< 

.PHONY: clean

clean:
	rm -f *.o *~ $(TARGET)

run:
	./$(TARGET)
