blogmd: main.c output.c style.c
	gcc -Wall -Wextra -o blogmd main.c output.c style.c -lcmark-gfm -lcmark-gfm-extensions
