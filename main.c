#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmark.h"

int main() {
    FILE *fp = fopen("mod5.md", "r");
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *markdown = malloc(fsize + 1);
    fread(markdown, fsize, 1, fp);
    fclose(fp);
    markdown[fsize] = 0;
}
