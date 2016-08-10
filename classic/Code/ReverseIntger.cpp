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
    int reverse(int x) {
        if(x==0)return 0;
        if(x<0)return -1*reverse(abs(x));
        int t=x;
        int c=0;
        cout<<"x: "<<x<<" c: "<<c<<" t: "<<t<<endl;
        while (t!=0){
            t=t/10;
            c++;
        }
        return reverse(x/10)+(x%10)*pow(10,c-1);
        //return reverse(x/10)+(x%10)*1E(c-1);
    }
};

int main(int argc,char**argv){
    Solution s ;
    cout<<s.reverse(-123)<<endl;
    return 0;
}

