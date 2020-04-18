CC=g++
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage

all: tests
tests.o: tests.cpp
	${CC} -c tests.cpp -o tests.o ${CFLAGS}
stack.o: stack.cpp
	${CC} -c stack.cpp -o stack.o ${CFLAGS}
tests: tests.o stack.o
	${CC} stack.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../stack_cpp.tgz ../stack_cpp

