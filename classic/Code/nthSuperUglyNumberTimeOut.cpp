#include <sstream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <string>
#include <vector>
#include <stack>  
#include <queue>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int> > candidate;
        candidate.push(1);
        int counter=1;
        while(counter<n){
            for(int i=0;i<primes.size();i++){
                if(candidate.top()*primes[i]>candidate.top()){
                    candidate.push(candidate.top()*primes[i]);
                }
            }
            candidate.pop();
            counter++;
        }
        int ret = candidate.top();
        return ret;
    }
};

int main(){
    int n = 200000;
    Solution * s = new Solution();
    int primes_arr [] = {2,3,5,13,19,29,31,41,43,53,59,73,83,89,97,103,107,109,127,137,139,149,163,173,179,193,197,199,211,223,227,229,239,241,251,257,263,269,271,281,317,331,337,347,353,359,367,373,379,389,397,409,419,421,433,449,457,461,463,479,487,509,521,523,541,547,563,569,577,593,599,601,613,619,631,641,659,673,683,701,709,719,733,739,743,757,761,769,773,809,811,829,857,859,881,919,947,953,967,971};
    int M = sizeof(primes_arr)/sizeof(int);
    vector<int> primes;
    for(int i=0;i<M;i++){
        primes.push_back(primes_arr[i]);
    }
    cout<<s->nthSuperUglyNumber(200000,primes)<<endl;
}

