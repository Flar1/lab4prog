// delim: +
// dir: /home/stud
// paths: ~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc
// Выход:

// new paths: ~/games/packman.cpp+/home/stud/alex/docs+~/study/Prog/lab4.c +/usr/bin/gcc

#include <stdio.h>
#include "mystrings.h"
#include <stdlib.h>
#define max_len 2000

char *input(char *delim, char *dir)
{
    char ch;
    char *paths = malloc(max_len);
    printf("delim: ");
    scanf("%c%c", delim, &ch);
    while (ch != '\n')
    {
        scanf("%c", &ch);
    }
    printf("dir: ");
    fgets(dir, max_len, stdin);
    dir[my_strlen(dir) - 1] = '\0';
    printf("paths: ");
    fgets(paths, max_len, stdin);
    paths[my_strlen(paths) - 1] = '\0';
    return paths;
}

char *process(char *delim, char *dir, char *paths)
{
    char *del_f = my_strtok(paths, delim);
    char *new_paths = calloc(1024, sizeof(char));
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
            my_strcat(new_paths, p);
            free(p);
        }
        else
        {
            my_strcat(new_paths, del_f);
            my_strcat(new_paths, delimiter);
        }

        del_f = my_strtok(NULL, delim);
    }
    if (my_strlen(new_paths) > 0 && new_paths[my_strlen(new_paths) - 1] == delim)
    {
        new_paths[my_strlen(new_paths) - 1] = '\0';
    }
    printf("%s\n", paths);
    free(del_f);
    free(delimiter);
    return new_paths;
}
void output(char* new_paths)
{
    printf("new paths: %s\n", new_paths);
}

