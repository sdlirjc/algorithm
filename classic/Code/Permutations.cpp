class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int n=num.size();
        vector<vector<int> >ret;
        if(n==0)return ret;
        if(n==1){
            ret.push_back(num);
        }
        for(int i=0;i<n;i++){
            int m=num[i];
            vector<int>v;
            for(int j=0;j<n;j++){
                if(i!=j){
                    v.push_back(num[j]);
                }
            }
            vector<vector<int> >mediate=permute(v);
            for(int j=0;j<mediate.size();j++){
                mediate[j].push_back(m);
                ret.push_back(mediate[j]);
            }
        }
    }
};
