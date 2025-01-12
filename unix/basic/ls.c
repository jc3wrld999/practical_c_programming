
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char * argv[])
{
    DIR *dir;
    struct dirent *dirp;

    if (argc != 2)
        printf("usage: ls directory_name");

    if ((dir = opendir(argv[1])) == NULL)
        printf("cat't open %s", argv[1]);
    while ((dirp = readdir(dir)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dir);
    exit(0);
}