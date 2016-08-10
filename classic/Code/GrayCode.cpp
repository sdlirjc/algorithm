class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        if(n==0) {v.push_back(0);return v; }
        if(n==1) {v.push_back(0);v.push_back(1);return v;}
        else{
            vector<int> v=grayCode(n-1);
            int oldN=v.size();
            for(int i=oldN-1;i>=0;i--)v.push_back(v[i]);
            for (int i=oldN;i<v.size();i++){
                v[i]=1<<(n-1)|v[i];
            }
            return v;
        }
    }
};
