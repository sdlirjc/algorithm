#include "header.h"

class Solution {

public:

    double pow(double x, int n) {
        if(n==0)return 1;

        if(n==1)return x;
        if(n==-1)return 1.0/x;

        int m=n/2;
        cout<<"m: "<<m<<endl;
        double h=pow(x,m);
        if(n%2==0)return h*h;
        else{
            if (n<0)return h*h/x;
            else{return h*h*x;}
        }
    }

};

int main(int argc,char**argv){
    Solution s ;
    //cout<<s.pow(1.0,-2147483648)<<endl;
    cout<<s.pow(34.00515,-3)<<endl;
    return 0;
}

