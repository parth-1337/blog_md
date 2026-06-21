blog_gen: main.c output.c
	gcc -Wall -Wextra -o blog_gen main.c output.c -lcmark-gfm -lcmark-gfm-extensions
