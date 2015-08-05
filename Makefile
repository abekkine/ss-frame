BUILD := debug

cflags.common = -Wall -Wextra -Werror -Wfatal-errors
cflags.debug = -g -O0
cflags.coverage = -g -O0 -coverage

TARGET=main.bin
SRCS=$(wildcard *.cpp) $(wildcard models/*.cpp) $(wildcard interfaces/*.cpp)
OBJS=$(SRCS:%.cpp=%.o)
FLAGS=${cflags.${BUILD}} ${cflags.common}
CCLIBS=-lrt

all: $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS) $(CCLIBS)

.cpp.o:
	$(CXX) $(FLAGS) -c -o $*.o $<

clean:
	$(RM) -rf report $(TARGET) *.o *~ core* *.gcda *.gcno report.info

cppcheck:
	/usr/bin/cppcheck . --enable=all

cpplint:
	/usr/local/bin/cpplint.py --linelength=100 $(SRCS)

coverage:
	./$(TARGET)
	lcov -o report.info -c -d .
	genhtml -o report --no-branch-coverage report.info

memcheck:
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes --num-callers=20 --error-limit=no ./$(TARGET)
