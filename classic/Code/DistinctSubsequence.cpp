class Solution {
public:
    int numDistinct(string S, string T) {
        int m=S.size();
        int n=T.size();
        vector<int> match(n+1,0);
        if(m<n)return 0;
        //http://fisherlei.blogspot.com/2012/12/leetcode-distinct-subsequences_19.html
        //i=0;j=0~T.size()
        match[0]=1;
        for(int i=0;i<m;i++){//larger str
            for(int j=n-1;j>=0;j--){//substr
                if(S[i]==T[j]){
                    match[j+1]+=match[j];
                }
            }
        }
        return match[n];
    }
};