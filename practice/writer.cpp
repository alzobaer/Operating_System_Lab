#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
   // key value for the shared memory segment
   key_t key = 12345;

   // create a shared memory segment with size of 1024 bytes
   int shmid = shmget(key, 1024, IPC_CREAT | 0666);
   if (shmid < 0) {
      perror("shmget");
      return 1;
   }

   // attach the shared memory segment to the process's address space
   char *data = (char *)shmat(shmid, (void *)0, 0);
   if (data == (char *)(-1)) {
      perror("shmat");
      return 1;
   }

   // write data to the shared memory segment
   sprintf(data, "Hello, Shared Memory!");

   // detach the shared memory segment from the process's address space
   if (shmdt(data) == -1) {
      perror("shmdt");
      return 1;
   }

   return 0;
}
