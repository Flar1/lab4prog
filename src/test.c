// delim: +
// dir: /home/stud
// paths: ~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc
//new paths: ~/games/packman.cpp+/home/stud/alex/docs+~/study/Prog/lab4.c +/usr/bin/gcc
#include <stdio.h>
#include "mystrings.h"
#include <stdlib.h>
int main()
{
    char s[1000] = "~/games/packman.cpp+~alex/docs+~/study/Prog/lab4.c+/usr/bin/gcc";
    char dir[1000] = "/home/stud";
    char delim = '+';
    char *del_f= my_strtok(s,delim);
    char *paths = calloc(1024,sizeof(char));
    //printf("%s",dir);
    while (del_f != NULL)
    {
        if (del_f[0] == '~' && del_f[1] != '/')
        {
            printf("%ld\n",my_strlen(dir));
            char *p = malloc(1024 *sizeof(char));
            my_strcat(p,dir);
            del_f[0] = '/';
            my_strcat(p,del_f);
            printf("%s\n",p);
            my_strcat(paths,p); 
        }
        else
        {
            my_strcat(paths,del_f);
        }
    //printf("%s",paths);
    //printf ("%s\n",del_f);
    del_f = my_strtok (NULL,delim);
   }
   printf("%s\n",paths);

}