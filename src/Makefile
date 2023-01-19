CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -fprofile-arcs -ftest-coverage
LDFLAGS="-lgcov"
TFLAGS=`pkg-config --cflags --libs check`
SANITIZER=#-fsanitize=address

test: fclean
	$(CC) -c $(CFLAGS) $(SANITIZER) $(LDFLAGS) s21_sprintf.c s21_sprintf_tests.c s21_string.h
	$(CC) $(CFLAGS) $(LDFLAGS) *.o -o s21_sprintf_tests $(TFLAGS)

coverage-test: test
	./s21_sprintf_tests
	lcov -c -d . -o index.info
	genhtml index.info --output-directory html --ignore-errors source
coverage:
	make --ignore-errors coverage-test
clean:
	rm -rf *.o
	rm -rf *.gch
	rm -rf *.gcno
	rm -rf *.gcda
fclean:
	rm -rf s21_sprintf
	rm -rf s21_sprintf_tests
	make clean
	rm -rf html
	rm -rf *.info
