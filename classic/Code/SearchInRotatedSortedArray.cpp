class Solution {
public:
    int search(int A[], int n, int target) {
        if(n==1){
            if(A[0]==target) {return 0;}
            else{return -1;}
        }
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(m==l&&m==r){
                if(A[m]==target){return m;}
                else{return -1;}
            }
            if(A[m]==target){return m;}
            if(A[m]<target){
                if(A[m]<A[l]){
                    if(target<A[r]){
                        l=m+1;
                    }else if (target>A[r]){
                        r=m-1;
                    }else{
                        return r;
                    }
                }else{
                    l=m+1;
                }
            }else{
                if(A[m]>=A[l]){
                    if(target>A[l]){
                        r=m-1;
                    }else if (target<A[l]){
                        l=m+1;
                    }else{
                        return l;
                    }
                }else{
                    r=m-1;
                }
            }
        }
        return -1;
    }
};
