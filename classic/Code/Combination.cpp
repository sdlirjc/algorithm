class Solution {
public:
    void getComb(vector<vector<int> >&result,vector<int>&solution,int n,int k,int level){
        if(solution.size()==k){
            result.push_back(solution);
            return ;
        }
        for(int i=level;i<=n;i++){
            solution.push_back(i);
            getComb(result,solution,n,k,i+1);
            solution.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> solution;
        getComb(result,solution,n,k,1);
        return result;
    }
};
