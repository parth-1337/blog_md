blog_gen: main.c output.c style.c
	gcc -Wall -Wextra -o blog_gen main.c output.c style.c -lcmark-gfm -lcmark-gfm-extensions
