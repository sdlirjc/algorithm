#include "header.h"
class Solution {
public:
    void get(vector<vector<int> >&result,vector<int>&solution,int sum,int level,vector<int>candidates,int target){
        if(sum>target){
            return ;
        }
        if(sum==target){
            result.push_back(solution);
            return;
        }else{
            for(int i=level;i<candidates.size();i++){
                sum+=candidates[i];
                solution.push_back(candidates[i]);
                get(result,solution,sum,i+1,candidates,target);
                solution.pop_back();
                sum-=candidates[i];
                while(i<candidates.size()-1&&candidates[i]==candidates[i+1]){i++;}
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector< vector<int> >result;
        vector<int> solution;
        int sum=0;
        
        if(target<=0)return result;
        sort(num.begin(),num.end());
        
        get(result,solution,sum,0,num,target);
        return result;
    }
};
int main(){
    Solution s;
    int array[]={13,23,25,11,7,26,14,11,27,27,26,12,8,20,22,34,27,17,5,26,31,11,16,27,13,20,29,18,7,14,13,15,25,25,21,27,16,22,33,8,15,25,16,18,10,25,9,24,7,32,15,26,30,19};
    vector<int>num;
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
        num.push_back(array[i]);
    }
    s.combinationSum2(num,25);
}
