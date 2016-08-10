class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool> >P(n,vector<bool>(n,false));
        vector<int>D(n+1,0);
        for(int i=0;i<=n;i++){
            D[i]=n-i;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<2||P[i+1][j-1])){
                    P[i][j]=true;
                    D[i]=min(D[i],D[j+1]+1);
                }
            }
        }
        return D[0]-1;
    }
};
