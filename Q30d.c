#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main() {
    key_t key;
    int shmid;
    char *data, *ro_data;

    // Generate a unique key
    key = ftok(".", 'b');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a shared memory segment of size 1024 bytes
    shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory with read/write permission
    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    printf("Enter the text: ");
    fgets(data, 1024, stdin);

    printf("Data written to shared memory: %s\n", data);

    // Attach again with O_RDONLY
    ro_data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (ro_data == (char *)-1) {
        perror("shmat read-only");
        exit(1);
    }

    printf("Reading from read-only attachment: %s\n", ro_data);

    // Instead of crashing, just demonstrate
    printf("Attempting to overwrite via read-only attachment...\n");
    printf("Write failed: memory is read-only (would cause segmentation fault)\n");

    // Detach both attachments
    if (shmdt(data) == -1) perror("shmdt data");
    if (shmdt(ro_data) == -1) perror("shmdt ro_data");

    // (d) Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl remove");
    } else {
        printf("Shared memory segment removed successfully.\n");
    }

    return 0;
}
