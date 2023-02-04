#include<stdio.h>
#include<stdlib.h> 
#include <unistd.h>

int* retAddr()
{
    int num=10;
    return&num;
}

void wild()
{
    int* p=NULL;
    p=retAddr();
    //p=malloc(sizeof(int));
    free(p); 
    printf("%p\n",p);
    printf("%p\n",&p);
    printf("%d\n",*p);
    p=NULL;
    printf("%p\n",p);
    printf("%p\n",&p);
    printf("%d\n",*p);
}

void test_init(){
    int * p=NULL;
    printf("%p\n",p);
    int * q;
    printf("%p\t",q);
    printf("%d\n",*q);
    const long m = 99999999999;
    const long n = m*sizeof(int);
    q=(int*)malloc(n);
    //q=(int*)calloc(99999999,sizeof(int));
    printf("%p\t", q);
    printf("%d\n",*q);
    for(int i=0;i<3;i++){
        printf("%d %p %d\n", i, q+i, q[i]);
    }
    long i = m-1; 
    printf("%ld %p %d\n", i, q+i, q[i]);
    printf("%lu\n", sizeof(q));
    for(int i=0;i<3;i++){
        int * t=calloc(1,sizeof(int));
        //t[0]=5;
        printf("%p %d\n", t, *t);
    }
    sleep(3000);
}

void test_str(){
    char * str;
    printf("%s\n", str);
}

int main()
{
    char * str="abc";
    puts(str);
    printf("%s\n",str);
    printf("%p\n",&str);
    printf("%c\n",*str);
    str="bcd";
    printf("%s\n",str);
    //str[0]='b';
    wild();
    //test_init();
    //test_str();    
    return 0;
}
