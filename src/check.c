// delim: +
// dir: /home/stud
// paths: ~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc
// Выход:

// new paths: ~/games/packman.cpp+/home/stud/alex/docs+~/study/Prog/lab4.c +/usr/bin/gcc

#include <stdio.h>
#include <mystrings.h>
#define max_len 2000

char* input(char* delim, char* dir)
{
    char ch;
    char* paths = malloc(max_len);
    printf("delim: ");
    scanf("%c%c", delim, &ch);
    while (ch != '\n') {
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

char *process(char* delim, char *dir, char* paths)
{
    char *s = my_strtok(paths,delim);
    
}
