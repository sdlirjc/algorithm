class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int n=L.size();
        int m=L[0].size();
        vector<int>res;
        if(n==0){return res;}
        map<string,int>mL;
        for(int i=0;i<n;i++){
            mL[L[i]]++;
        }
        int i=0;
        while(i+n*m-1<S.size()){
            map<string,int>mS;
            int j=0;
            while(j<n){
                string subs=S.substr(i+j*m,m);
                if(mL.find(subs)==mL.end()){
                    break;
                }else{
                    mS[subs]++;
                    if(mS[subs]>mL[subs]){
                        break;
                    }
                }
                j++;
            }
            if(j==n){res.push_back(i);}
            i++;
        }
        return res;
    }
};
