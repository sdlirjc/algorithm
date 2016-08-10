class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n==1)return A[0];
        int negative=0;
        int positive=0;
        int val=0;
        for(int i=0;i<n;i++){
            if(A[i]>0){
                negative=min(A[i]*negative,A[i]);
                positive=max(A[i]*positive,A[i]);
            }else{
                int newNegative=min(A[i]*positive,A[i]);
                positive=max(A[i]*negative,A[i]);
                negative=newNegative;
            }
            val=max(val,positive);
        }
        return val;
    }
};
