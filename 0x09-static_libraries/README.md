0x09-static_libraries

1-gcc -c *.c
2-ar rc libmy.a *.o
3-ar -t libmy.a
4-nm libmy.a
5-vim main.c
6-gcc -std=gnu89 main.c -L. -lmy -o quote
7-./quote

result : "At the end of the day, my goal was to be the best hacker"
	- Kevin Mitnick

