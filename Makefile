TARGET=main.bin
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)
FLAGS=-Wall -Wextra -Werror -Wfatal-errors
CCLIBS=

all: $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS) $(CCLIBS)

.cpp.o:
	$(CXX) $(FLAGS) -c -o $*.o $<

clean:
	$(RM) $(TARGET) *.o *~ core*