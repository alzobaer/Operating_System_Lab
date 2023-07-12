#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int fd2[2];

    int val = 0;

    // create pipe descriptors
    pipe(fd);
    pipe(fd2);

    // fork() returns 0 for child process, child-pid for parent process.
    if (fork() != 0) {
            ///0. Send: 0
            // parent: writing only, so close read-descriptor.
            close(fd[0]);

            // send the value on the write-descriptor.
            val = 0;
        resend:
            write(fd[1], &val, sizeof(val));
            printf("0.Parent(%d) send value: %d\n", getpid(), val);

            // close the write descriptor
            close(fd[1]);

            ///3. Receive 1;
            close(fd2[1]);

            // now read the data
            read(fd2[0], &val, sizeof(val));
            printf("3.Parent(%d) received value: %d\n", getpid(), val);

            // close the read-descriptor
            close(fd2[0]);
            wait(NULL);
            val++;
            if (val < 6)
                goto resend;
            else
                return 0;

    } else {   // child: reading only, so close the write-descriptor
        childStart:
        wait(NULL);

        ///1. receive: 0
            close(fd[1]);

            // now read the data (will block)
            read(fd[0], &val, sizeof(val));
            printf("1.Child(%d) received value: %d\n", getpid(), val);

            // close the read-descriptor
            //close(fd[0]);

            ///2. Send: 1
            // parent: writing only, so close read-descriptor.
            close(fd2[0]);

            // send the value on the write-descriptor.
            val = val + 1;
            write(fd2[1], &val, sizeof(val));
            printf("2.Child(%d) send value: %d\n", getpid(), val);

            // close the write descriptor
            close(fd2[1]);
            if(val <5) {
                wait(NULL);
                goto childStart;
            }
            else
                return 0;
        }
        ///////////////////////////////////////////////////////////////////////////////////

    return 0 ;
    }