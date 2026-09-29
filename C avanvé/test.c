#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    float b;
    char c;
    long d;
}S;


int main(void) {
    char* p=malloc(1024*1024*1024);
    printf("p=%p\n",p);
    printf("Bonjour le monde !\n");
    printf("la taille du int est : %d\n",sizeof(int));
    printf("la taille de la structure est : %d",sizeof(S));
    return 0;
}