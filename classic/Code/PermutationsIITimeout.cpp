#include"header.h"
class Solution {
public:

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> >ret;
        vector<int>solution;
        int n=num.size();
        if(n==0)return ret;
        if(n==1){
            ret.push_back(num);
            return ret;
        }
        vector<int >visited(n,0);
        sort(num.begin(),num.end());
        return permute(num,0,visited,solution,ret);
        
    }
    vector<vector<int> > permute(vector<int> &num,int step,vector<int>&visited,
        vector<int>&solution,vector<vector<int> >&ret) {
        int n=num.size();
        if(step==n){
            ret.push_back(solution);
            return ret;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(i>0&&num[i-1]==num[i]&&visited[i-1]==0){
                    continue;
                }
                visited[i]=1;
                int m=num[i];
                solution.push_back(m);
                permute(num,step+1,visited,solution,ret);
                solution.pop_back();
                visited[i]=0;
            }
        }
        return ret;
    }
};
int main(){
    Solution s;
    vector<int>input;
    input.push_back(1);
    input.push_back(1);
    s.permuteUnique(input);
}


