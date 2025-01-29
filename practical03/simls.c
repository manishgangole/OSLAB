#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    char dirname[100];
    DIR *p;
    struct dirent *d;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    p = opendir(dirname);
    if (p == NULL) {
        perror("Cannot find directory");
        exit(-1);
    }

    while ((d = readdir(p)) != NULL) {
        printf("%s\n", d->d_name);
    }

    closedir(p);
    return 0;
}
