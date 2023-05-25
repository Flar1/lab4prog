// delim: +
// dir: /home/stud
// paths: ~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc
//new paths: ~/games/packman.cpp+/home/stud/alex/docs+~/study/Prog/lab4.c +/usr/bin/gcc
#include <stdio.h>
#include "mystrings.h"
#include <stdlib.h>
#include <stdio.h>
#include "mystrings.h"
#include <stdlib.h>

int main()
{
    char s[1000] = "~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc";
    char dir[1000] = "/home/stud";
    char delim = '+';
    char *del_f = my_strtok(s, delim);
    char *paths = calloc(1024, sizeof(char));
    char *delimiter = malloc(2 * sizeof(char));
    delimiter[0] = delim;
    delimiter[1] = '\0';

    while (del_f != NULL)
    {
        if (del_f[0] == '~' && del_f[1] != '/')
        {
            char *p = malloc(1024 * sizeof(char));
            my_strcat(p, dir);
            del_f[0] = '/';
            my_strcat(p, del_f);
            my_strcat(p, delimiter);
            my_strcat(paths, p);
            free(p);
        }
        else
        {
            my_strcat(paths, del_f);
            my_strcat(paths, delimiter);

        }

        del_f = my_strtok(NULL, delim);
    }
    if (my_strlen(paths) > 0 && paths[my_strlen(paths) - 1] == delim) {
    paths[my_strlen(paths) - 1] = '\0';
    }
    printf("%s\n", paths);
    free(del_f);
    free(paths);
    free(delimiter);

    return 0;
}
