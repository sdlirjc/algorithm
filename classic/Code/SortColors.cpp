class Solution {
public:
    void sortColors(int A[], int n) {
        int r=0;
        int b=n-1;
        int i=0;
        while (i<=b){
            if(A[i]==0){
                swap(A[i],A[r]);
                r++;
                i++;
                continue;
            }
            if(A[i]==2){
                swap(A[i],A[b]);
                b--;
                continue;
            }
            i++;
        }
        
    }
};
