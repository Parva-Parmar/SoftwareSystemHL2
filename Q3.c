#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

 
int main() {
    struct rlimit lim;
 
    lim.rlim_cur = 1024 * 1024;   // soft limit (1 MB)
    lim.rlim_max = 1024 * 1024;   // hard limit (1 MB

    // Now apply the limit
    if (setrlimit(RLIMIT_FSIZE, &lim) == -1) {
        perror("setrlimit failed");   
        exit(1);
    }

    printf("I have set the file size limit to 1 MB successfully!\n");

    FILE *fp = fopen("myfile.txt", "w");
    if (fp == NULL) {
        perror("fopen failed");
        exit(1);
    }

    for (int i = 0; i < (1024 * 1024) + 100; i++) {
        fputc('A', fp);
    }

    fclose(fp);
    printf("Tried writing more than 1 MB into file.\n");

    return 0;
}
