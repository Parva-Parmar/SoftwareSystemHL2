#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == -1) {
        perror("getrlimit");
        return;
    }

    printf("%-25s : ", name);

    if (limit.rlim_cur == RLIM_INFINITY)
        printf("Current = unlimited, ");
    else
        printf("Current = %ld, ", (long)limit.rlim_cur);

    if (limit.rlim_max == RLIM_INFINITY)
        printf("Max = unlimited\n");
    else
        printf("Max = %ld\n", (long)limit.rlim_max);
}

int main() {
    printf("=== System Resource Limits ===\n");
    
    print_limit(RLIMIT_CPU, "CPU time (seconds)");
    print_limit(RLIMIT_FSIZE, "File size (bytes)");
    print_limit(RLIMIT_DATA, "Data segment size (bytes)");
    print_limit(RLIMIT_STACK, "Stack size (bytes)");
    print_limit(RLIMIT_CORE, "Core file size (bytes)");
    print_limit(RLIMIT_RSS, "Resident set size");
    print_limit(RLIMIT_NPROC, "Max number of processes");
    print_limit(RLIMIT_NOFILE, "Max open files");
    print_limit(RLIMIT_MEMLOCK, "Locked memory");
    print_limit(RLIMIT_AS, "Address space (bytes)");

    return 0;
}
