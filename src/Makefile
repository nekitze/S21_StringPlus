NAME = s21_string
CC = gcc
CC_FLAGS = -std=c11 -Wall -Wextra -Werror -g
TEST_FLAGS = -std=c11 -g
GCOVFLAGS = -L. -ls21_string --coverage
OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

TEST_COMPILE = $(CC) $(TEST_FLAGS) tests/*.c libs21_string.a $(CHECK_FLAGS) -L. -ls21_string

all: clean s21_string.a

clean:
	rm -rf *.o *.g* *.info *.out report *.a *.dSYM debug

rebuild: clean all

test: s21_string.a
	$(TEST_COMPILE)
	./a.out

debug: clean s21_string.a
	gcc -std=c11 -Wall -Wextra -g debug.c libs21_string.a
	./a.out

gcov_report: s21_string.a test
	rm -f *.g*
	$(CC) $(TEST_FLAGS) s21_a*.c s21_m*.c s21_s*.c tests/*.c libs21_string.a $(CHECK_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno s21_tests s21_tests.info

s21_string.a: s21_string.o
	ar rcs libs21_string.a *.o
	rm -rf *.o
	ranlib libs21_string.a
	cp libs21_string.a s21_string.a
	cp libs21_string.a ls21_string.a

s21_string.o:
	$(CC) $(CC_FLAGS) -c s21*.c

check:
	clang-format -style=google -i *.c *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./a.out
else
	valgrind ./a.out --leak-check=full
endif
	make clean
