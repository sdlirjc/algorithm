class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n==0)return 1;
        if(n==1){
            if(A[0]<0){
                return 0;
            }else if (A[0]==1){
                return 2;
            }else{
                return 1;
            }
        }
        int i=0;
        while(i<n)
        if(A[i]!=i+1&&A[i]>=1&&A[i]<=n&&A[i]!=A[A[i]-1]){
            swap(A[i],A[A[i]-1]);
            
        }else {
            i++;
        }
        for(i=0;i<n;i++){
            
            if(A[i]!=i+1){
                return i+1;
            }
        }
        return A[n-1]+1;
    }
};
