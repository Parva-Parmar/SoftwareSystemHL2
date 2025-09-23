#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    mknod("fifo_syscall", S_IFIFO | 0666, 0);

    mkfifo("fifo_lib", 0666);

    return 0;
}
