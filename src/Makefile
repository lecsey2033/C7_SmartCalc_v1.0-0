CC=gcc
CFLAGS=-Wall -Wextra -Werror -g -std=c11
LIBS=-lcheck
LFLAGS=-fprofile-arcs -ftest-coverage

all: clean SmartCalc.a test

SmartCalc.a: SmartCalc.o
	ar rcs SmartCalc.a SmartCalc.o
	cp SmartCalc.a libSmartCalc.a
	cp SmartCalc.a lSmartCalc.a
	ranlib libSmartCalc.a
	ranlib lSmartCalc.a

SmartCalc.o: SmartCalc.c
	$(CC) $(CFLAGS) -c SmartCalc.c -o SmartCalc.o

test: SmartCalc.a
	$(CC) $(CFLAGS) test.c SmartCalc.a -o test.out $(LIBS)
	./test.out

gcov_report: SmartCalc.c
	$(CC) $(CFLAGS) $(LFLAGS) test.c SmartCalc.c -o test.out $(LIBS)
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

open:
	open report/index.html

rebuild: clean all

check:
	cp ../materials/linters/CPPLINT.cfg ./
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
	CK_FORK=no leaks --atExit -- ./test.out
	make clean
	rm -rf CPPLINT.cfg

clean:
	rm -rf *.gc* *.o *.a *.out *.info test.out
	rm -rf report

Smart: SmartCalc.a
	$(CC) $(CFLAGS) SmartCalc.a -o test.out $(LIBS)
	./test.out