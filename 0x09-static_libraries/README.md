0x09-static_libraries

1-gcc -c *.c <br>
2-ar rc libmy.a *.o <br>
3-ar -t libmy.a <br>
4-nm libmy.a <br>
5-vim main.c <br>
6-gcc -std=gnu89 main.c -L. -lmy -o quote <br>
7-./quote <br>

<br><br>

result : "At the end of the day, my goal was to be the best hacker"
	- Kevin Mitnick

