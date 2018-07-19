#include <iostream>
#include <cstdlib>
#include <pthread.h>

#define THREADS 5

/**
 * This simple example code creates 5 threads with the pthread_create()
 * routine. Each thread prints a "Hello World!" message, and then terminates with a call to pthread_exit().
 **/

void *PrintHello(void *threadid) {
    long tid;
    tid = (long)threadid;
    std::cout << "Hello World Thread ID: " << tid << std::endl;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t threads[THREADS];
    int rc;
    int i;

    for(i = 0; i < THREADS; i++)
    {
        std::cout << "main(): create thread, " << i << std::endl;

        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

        if (rc) {
            std::cout << "Error: unable to create thread, : " << rc << std::endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);

    std::cout << std::endl;
}
