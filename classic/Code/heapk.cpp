#include <iostream>
#include <string>
#include <vector>
#include <stack>  
#include <time.h>       /* time */
#include <stdlib.h>     /* srand, rand */
using namespace std;
class Solution {
public:
    void k(const int input[],const int N,const int m){
        int output[m];
        for(int i=0;i<m;i++){output[i]=input[i];}
        for (int i=0;i<N;i++){
            for(int j=0;j<m;j++){
                if(output[j]>input[i]){
                    output[j]=input[i];
                    break;
                }
            }
        }
        for(int i=0;i<m;i++){
            cout<<output[i]<<" ";  
        } 
        cout<<endl;
    }
    Solution(){}
};
int main(){
    srand (time(NULL));
    const int N=1000000;
    int input[N];
    const int m=100;
    for (int i=0;i<N;i++) input[i]=rand()%N;
    
    Solution * s = new Solution();
    s->k(input,N,m);
}
