
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int     main(void)
{
        int     fd;

        fd = open("text.txt", O_RDONLY);
//      get_next_line(fd);
//      get_next_line(fd);
//      get_next_line(fd);

        char    *a = get_next_line(fd);
        printf("Primeira parte:\n%s", a);
        free(a);
        printf("\nsegunda parte:\n");
        char    *b = get_next_line(fd);
        printf("%s", b);
        free(b);
        printf("\nterceira parte:\n");
        char    *c = get_next_line(fd);
        printf("%s", c);
        free(c);
        char    *d = get_next_line(fd);
        printf("\n%s", d);
        free(d);
        char    *e = get_next_line(fd);
        printf("\n%s", e);
        free(e);
        char    *f = get_next_line(fd);
        printf("\n%s", f);
        free(f);
        char    *h = get_next_line(fd);
        printf("\n%s", h);
        free(h);
        printf("\n%s", get_next_line(fd));
        printf("\n%s\n\n", get_next_line(fd));
//      close(fd);
}
