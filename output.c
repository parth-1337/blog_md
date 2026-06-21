#include "output.h"
#include "style.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmark-gfm.h>
#include <cmark-gfm-core-extensions.h>

void gen_file() {

    FILE *fp = fopen("ssg.md", "r");
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *markdown = malloc(fsize + 1);
    fread(markdown, fsize, 1, fp);
    fclose(fp);
    markdown[fsize] = 0;

    cmark_gfm_core_extensions_ensure_registered();
    cmark_parser *parser = cmark_parser_new(CMARK_OPT_DEFAULT);
    
    cmark_syntax_extension *table_ext = cmark_find_syntax_extension("table");
    cmark_parser_attach_syntax_extension(parser, table_ext);

    cmark_parser_feed(parser, markdown, strlen(markdown));
    cmark_node *document = cmark_parser_finish(parser);
    
    cmark_llist *exts = cmark_parser_get_syntax_extensions(parser);
    char *html_body = cmark_render_html(document, CMARK_OPT_DEFAULT, exts);

    const char *css = get_css();

    FILE *out = fopen("index.html", "w");
    if (out == NULL) {
        perror("Error opening index.html for writing");
        return; 
    }
    
    fprintf(out, "<!DOCTYPE html>\n<html>\n<head>\n");
    fprintf(out, "<meta charset=\"UTF-8\">\n");

    // add custom user input title later 
    
    fprintf(out, "<title>My Blog</title>\n");
    
   
    // toddo-- add dark light theme later custom

    fprintf(out, "<style>\n%s\n</style>\n", css);
    
    fprintf(out, "</head>\n<body>\n");
    
    fprintf(out, "%s", html_body);
    
    fprintf(out, "\n</body>\n</html>\n");
    fclose(out);

    free(markdown);
    free(html_body);
    cmark_parser_free(parser);
    cmark_node_free(document);

}