#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
    bool canWinNim(int n) {
        bool * dp = new bool[n];
        for(int i=0;i<n;i++){
            if (i<3) dp[i]=true;
            dp[i]=(!dp[i-1])||(!dp[i-2])||(!dp[i-3]);
        }
        return dp[n-1];
    }
};

int main(int argc, char**argv){
    Solution s;
    cout<<s.canWinNim(atoi(argv[1]))<<endl;
}
