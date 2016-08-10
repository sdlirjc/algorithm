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
                get(result,solution,sum,i,candidates,target);
                solution.pop_back();
                sum-=candidates[i];
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector< vector<int> >result;
        vector<int> solution;
        int sum=0;
        
        if(target<=0)return result;
        sort(candidates.begin(),candidates.end());
        
        get(result,solution,sum,0,candidates,target);
        return result;
    }

};
