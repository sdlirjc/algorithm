class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        
        
        
        
        vector<vector<int> >vval;
        unordered_set<string>vset;
        if(num.size()<4){return vval;}
        
        
        int i,j,k,m,sum;
        
        for (i=0;i<num.size();i++){
            if(i&& num[i]==num[i-1])continue;
            for(j=i+1;j<num.size();j++){
                if(j>i+1&&num[j]==num[j-1])continue;
                k=j+1;
                m=num.size()-1;
                while (k<m){
                    if(k>j+1&&num[k]==num[k-1]){
                        k++;
                        continue;
                        
                    }
                    if(m<num.size()-1&&num[m]==num[m+1]){
                        m--;
                        continue;
                    }
                    sum=num[i]+num[j]+num[k]+num[m];
                    if(sum==target){
                        vector<int>ans;
                        ans.push_back(num[i]);
                        ans.push_back(num[j]);
                        ans.push_back(num[k]);
                        ans.push_back(num[m]);
                        vval.push_back(ans);
                        k++;
                        m--;
                    }else if(sum<target){
                        k++;
                    }else{
                        m--;
                    }
                }
            }
        }
        return vval;
    }
};
