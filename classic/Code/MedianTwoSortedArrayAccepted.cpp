class Solution {
public:
    double find(int A[], int endA, int B[], int endB, int k){
        if(endA>endB){
            return find(B,endB,A,endA,k);
        }
        int midA=endA/2;
        int midB=endB/2;
        int mid=(endA+endB)/2;
        if(endA==0){return B[k-1];}
        if(k<=1){return min(A[0],B[0]);}
        int left=min(k/2,endA);
        int right=k-left;
        if (A[left-1]<B[right-1]){
            return find(A+left,endA-left,B,endB,k-left);
        }else if(A[left-1]>B[right-1]){
            return find(A,endA,B+right,endB-right,k-right);
        }else{
            return A[left-1];
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2==0){
            return (find(A,m,B,n,(m+n)/2)+find(A,m,B,n,(m+n)/2+1))/2;
        }else{
            return find(A,m,B,n,(m+n)/2+1);
        }
    }
};

