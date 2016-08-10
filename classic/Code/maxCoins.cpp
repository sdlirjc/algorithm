
#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        std::vector<int>::iterator it;
        it = nums.begin();
        it = nums.insert ( it , 1 );
        nums.push_back(1);
        vector<vector<int> >dp(nums.size(),vector<int>(nums.size(),0));
        for(int i=1;i<=n;i++){//length
            for(int j=1;j<=n-i+1;j++){//left
                for(int k=j;k<=i+j-1;k++){
                    dp[j][j+i-1]=max(dp[j][j+i-1],nums[k]*nums[j-1]*nums[j+i]+dp[j][k-1]+dp[k+1][j+i-1]);
                }
            }
        }
        return dp[1][n];
    }
};
int main(int argc, char**argv){
    Solution s;
    //int input[1]={3};
    //int input[2]={3,1};
    //int input[3]={3,1,5};
    int input[4]={3,1,5,8};
    vector<int>inputVec(begin(input),end(input));
    int maxCoins=s.maxCoins(inputVec);
    cout<<"maxCoins:"<<maxCoins<<endl;
}
