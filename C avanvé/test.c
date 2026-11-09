#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int a;
    float b;
    char c;
    long d;
}S;

char* multiply(int a, int b){
    char* result =malloc(50*sizeof(char));
    if (result!=0){
        sprintf(result,"\na*b=%d",a*b);
    }
    return result;
}


int main(void) {
    printf("hello word");
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%s",multiply(a,b));
  }
