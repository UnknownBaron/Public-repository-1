CC := gcc
CFLAGS := -std=c99 -Wall -Werror

build: main

main: main.o string.o
	$(CC) $(CFLAGS) -o app.exe $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

run: build
	./app.exe

clean:
	rm -f *.o ./app.exe out.txt
