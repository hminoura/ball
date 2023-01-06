TARGET = ball

SRCS   = main.cpp App.cpp Timer.cpp Rand.cpp BallApp.cpp Ball.cpp
OBJS   = $(SRCS:%.cpp=%.o)
## for macOS (SFML: brew)
#CXX    = clang++
#CXXFLAGS = -std=c++11 -Wc++11-extensions -g

## for Linux (SfLinux
CXX    = c++
CXXFLAGS = -std=c++11 -g
# LIBS     = -lsfml-graphics -lsfml-window -lsfml-system
LIBS	= `pkg-config --libs sfml-all`

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o  $@ $^ $(LDFLAGS) $(LIBS)
	strip $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< 

.PHONY: clean run

clean:
	rm -f *.o *~ $(TARGET)

run: $(TARGET)
	./$(TARGET)
