class Solution {
public:
    vector<vector<int>> help(int k, int n,int start) {
        vector<vector<int> > retVal;
        vector<int>emptyVector;
        retVal.push_back(emptyVector);
        if(k==0||n==0){return retVal;}
        for (int i=min(start,n);i>=1;i--){
            vector<vector<int> >sub = help(k-1,n-i,i-1);
            for(int j=0;j<sub.size();j++){
                sub[j].push_back(i);
                retVal.push_back(sub[j]);
            }
        }
        return retVal;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> >candidates = help(k,n,min(9,n));
        vector<vector<int> >retVal;
        for(int i=0;i<candidates.size();i++){
            if(candidates[i].size()==k){
                int tmp=0;
                for(int j=0;j<candidates[i].size();j++){
                    tmp+=candidates[i][j];
                }
                if(tmp==n){
                    retVal.push_back(candidates[i]);
                }
            }
        }
        return retVal;
    }
};
