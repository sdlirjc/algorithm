class Solution {
public:
    int trap(int A[], int n) {
        vector<int>l(n,0);
        vector<int>r(n,0);
        if(n<=2)return 0;
        int lm=0;
        int rm=0;
        for(int i=0;i<n;i++){
            int j=n-1-i;
            l[i]=lm;
            lm=max(lm,A[i]);
            r[j]=rm;
            rm=max(rm,A[j]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=max(0,min(l[i],r[i])-A[i]);
        }
        return total;
    }
};
