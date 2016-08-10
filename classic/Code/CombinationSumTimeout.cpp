class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector< vector<int> >vv;
        if(target<=0)return vv;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
            if(target==candidates[i]){
                vector<int> v;
                v.push_back(target);
                vv.push_back(v);
            }else{
                set<string>strset;
                vector<vector<int> > v=combinationSum(candidates,target-candidates[i]);
                for(int j=0;j<v.size();j++){
                    v[j].push_back(candidates[i]);
                    sort(v[j].begin(),v[j].end());
                    string str="";
                    for(int k=0;k<v[j].size();k++){
                        str+=v[j][k]+'0';
                    }
                    if(strset.find(str)==strset.end()){
                        vv.push_back(v[j]);
                        strset.insert(str);
                    }
                }
            }
        }
        return vv;
    }
};
