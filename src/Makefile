CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
TFLAGS=`pkg-config --cflags --libs check`
SANITIZER=#-fsanitize=address

test:
	$(CC) -c $(CFLAGS) $(SANITIZER) s21_sprintf.c s21_sprintf_tests.c s21_string.h
	$(CC) -g $(CFLAGS) *.o -o s21_sprintf_tests $(TFLAGS)
	make clean
	clear
	./s21_sprintf_tests
clean:
	rm -rf *.o
	rm -rf *.gch
fclean:
	rm -rf s21_sprintf
	rm -rf s21_sprintf_tests
	make clean