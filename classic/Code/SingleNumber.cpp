class Solution {
public:
    int singleNumber(int A[], int n) {
        int t[32];
        int sum=A[0];
        
        for(int i=0;i<32;i++) t[i]==0;
        for(int i=1;i<n;i++){
            sum=A[i]^sum;
            for(int j=0;j<32;j++){
//                t[j]+=(A[i]>>j)%2;
            }
        }
        for(int i=0;i<32;i++) {
//            sum+=(t[i]%2)*pow(2,i);
        }
        return sum;
    }
};
