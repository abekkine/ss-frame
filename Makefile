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

cppcheck:
	/usr/bin/cppcheck . --enable=all

cpplint:
	/usr/local/bin/cpplint.py --linelength=100 $(SRCS)