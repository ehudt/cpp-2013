CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		hw4.o

LIBS =

TARGET =	hw4

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
