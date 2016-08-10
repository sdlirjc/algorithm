#include"header.h"
class Solution {
public:
    int singleNumber(int A[], int n) {
        if(n==0){return 0;}
        vector<int>C(32,0);
        for(int i=0;i<n;i++){
            int tmp=A[i];
            for(int j=0;j<32;j++){
                cout<<"tmp:"<<tmp<<endl;
                C[32-1-j]+=tmp&1;
                tmp=tmp>>1;
            }
        }
        for(int i=0;i<32;i++){
            
            cout<<C[i]<<endl;
        }
        int num=0;
        for(int i=0;i<31;i++){
            if(C[i]%3>0){
                num=num|1;
            }
            num=num<<1;
        }
        if(C[31]%3>0){
            num=num|1;
        }
        return num;
    }
};
int main(){
    Solution s;
    //int A[]={1};int n=1;
    int A[]={2,2,3,2};int n=4;
    cout<<"num:"<<s.singleNumber(A,n)<<endl;
}
