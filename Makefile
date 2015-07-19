TARGET=main.bin
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:%.cpp=%.o)
FLAGS=-Wall -Wextra -Werror -Wfatal-errors
CCLIBS=

all: $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS) $(CCLIBS)

.cpp.o:
	$(CC) $(FLAGS) -c -o $*.o $<

clean:
	$(RM) $(TARGET) *.o *~ core*