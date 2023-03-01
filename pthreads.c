#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#define NUMBER_OF_THREADS 10

int *print_hello_world(int *tid)
{
    sleep(1);
    printf("Hello World. Greetings from thread %d\n", tid);
    pthread_exit(NULL);
    return tid;
}

int main(int argc, char *argv[])
{
    int status, i;
    int x, y, counter;
    
    printf("Enter number of threads and iterations: ");
    scanf("%d", &x);
    scanf("%d", &y);
    
    pthread_t threads[x];
    
    for(i=0; i<x; i++)
    {
        //write(1, argv[i], strlen(argv[i]));
        printf("Main here. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (int *)i);
        sleep(2);
        counter += y;
        if(status != 0)
        {
            printf("Oops. pthread_create returned error code %d\n", status);
            exit(-1);
        }

    }
    printf("Total Counter: %d", counter);
    exit(NULL);
}
