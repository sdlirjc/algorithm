class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> b(32,0);
        int r=0;
        
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                b[i]+=A[j]>>i&1;
            }
            b[i]=b[i]%3;
            r|=b[i]<<i;
        }
        return r;
                
    }
};
