class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(m==0){
            for(int i=0;i<n;i++){A[i]=B[i];}
            return;
        }
        if(n==0)return;
        int index=m+n-1;
        int iA=m-1;
        int iB=n-1;
        while (index>=0&&iA>=0&&iB>=0){
            if(A[iA]>B[iB]){A[index]=A[iA];iA--;}else{A[index]=B[iB];iB--;}
            index--;
        }
        while(iA>=0){
            A[index]=A[iA];
            iA--;
            index--;
        }
        while(iB>=0){
            A[index]=B[iB];
            iB--;
            index--;
        }
    }
};
