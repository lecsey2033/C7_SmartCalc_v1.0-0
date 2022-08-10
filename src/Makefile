GCC=gcc
CFLAGS=-Wall -Wextra -Werror -g -std=c11
LIBS=-lcheck
LFLAGS=-fprofile-arcs -ftest-coverage
LINUX = -lrt -lpthread -lm -lsubunit
OS=$(shell uname -s)

all: clean test

test:
ifeq ($(OS), Darwin)
	$(GCC) $(CFLAGS) test.c SmartCalc.c -o test.out $(LIBS)
	./test.out
else
	$(GCC) $(CFLAGS) test.c SmartCalc.c -o test.out $(LIBS) $(LINUX)
	./test.out
endif

gcov_report: SmartCalc.c
ifeq ($(OS), Darwin)
	$(GCC) $(CFLAGS) $(LFLAGS) test.c SmartCalc.c -o test.out $(LIBS)
else
	$(GCC) $(CFLAGS) $(LFLAGS) test.c SmartCalc.c -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	make open

open:
ifeq ($(OS), Darwin)
	open report/index.html
else
	xdg-open report/index.html
endif

rebuild: clean all

check:
	cp ../materials/linters/CPPLINT.cfg ./
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test.out
else
	valgrind ./test.out --leak-check=full
endif
	make clean
	rm -rf CPPLINT.cfg

clean:
	rm -rf *.gc* *.o *.a *.out *.info test.out test.out.dSYM
	rm -rf report

install: 
	make -C Release/ install

uninstall: 
	make -C Release/ uninstall
	rm -rf Release/*.app

dvi:
	open ./readme.html

dist:
	make -C Release/ dist

open_app:
	make -C Release/ open