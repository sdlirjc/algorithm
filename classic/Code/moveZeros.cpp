#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <iostream>
using namespace std;

class Solution {
public:
    int nextNonZero(int index, vector<int>& nums){
        int N=nums.size();
        if(index==N-1){
            return -1;
        }
        int indexNonZero=index+1;
        while(indexNonZero<nums.size()&&nums[indexNonZero]==0){
            indexNonZero++;
        }
        return indexNonZero>=N?-1:indexNonZero;
    }
    void moveZeroes(vector<int>& nums) {
        int indexNonZero=(nums[0]!=0?0:nextNonZero(0,nums));
        if(indexNonZero==-1){
            return;
        }
        for (int i=0;i<nums.size();i++){
            if(indexNonZero==-1){
                break;
            }
            if(nums[i]==0){
                nums[i]=nums[indexNonZero];
                nums[indexNonZero]=0;
                indexNonZero=nextNonZero(indexNonZero,nums);
            }
            indexNonZero=nextNonZero(i,nums);
        }
        for (int i=0;i<nums.size();i++){
            cout<<nums[i]<<endl;
        }
    }
};
int main1(int argc, char**argv){
    Solution s;
    vector<int>v;
    v.push_back(0);
    v.push_back(0);
    s.moveZeroes(v);
    return 0;
}
int main(int argc, char**argv){
    Solution s;
    vector<int>v;
    v.push_back(1);
    v.push_back(0);
    s.moveZeroes(v);
    return 0;
}
