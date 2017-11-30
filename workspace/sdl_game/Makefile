CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		sdl_game.o

LIBS =

TARGET =	sdl_game.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
