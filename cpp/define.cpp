#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

class A{
public:
    int a ;
    A(int _a){
        cout<<_a<<endl;
        a=_a;
    }
    A(){
        a=-1;
        cout<<-1<<endl;
    }
};

int main(){
    A a;
    A b(1);
    vector<int>c;
}
