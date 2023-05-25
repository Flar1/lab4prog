#include <stdio.h>
#include <stdlib.h>

#include "check.h"
#include "mystrings.h"
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
    //char *del_f = my_strtok(paths, delim);
    char *new_paths = calloc(1024, sizeof(char));
    char *delimiter = malloc(2 * sizeof(char));
    delimiter[0] = delim[0];
    delimiter[1] = '\0';
    char *del_f = my_strtok(paths, delimiter);
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
    if (my_strlen(new_paths) > 0 && new_paths[my_strlen(new_paths) - 1] == delim[0])
    {
        new_paths[my_strlen(new_paths) - 1] = '\0';
    }
    free(del_f);
    free(delimiter);
    return new_paths;
}
void output(char* new_paths)
{
    printf("new paths: %s\n", new_paths);
}

