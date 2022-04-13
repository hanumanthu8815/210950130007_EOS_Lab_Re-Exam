#include<stdio.h>
#include<pthread.h>

/*void *hello_thread(void *arg)
{
    printf("Hello thread\n");
}
void *bye_thread(void *arg)
{
    printf("Bye thread\n");
}*/
void *greet_thread(void *arg)
{
    printf("%s thread\n", arg);
}

int main(int argc,char const *argv[])
{
    pthread_t helloID,byeID;
    printf("Main thread: Before creating hello thread\n");

    pthread_create(&helloID,NULL,greet_thread,"Hello");
    pthread_create(&byeID,NULL,greet_thread,"Bye");
    pthread_join(helloID,NULL);
    pthread_join(byeID,NULL);

    printf("Main thread: After creating hello thread\n");

    return 0;
}
