class Solution {
public:
    bool search(int A[], int n, int target) {
        int start=0;
        int end=n-1;
        while (start<=end){
            int mid=(start+end)/2;
            if(target==A[mid]){return true;}
            if(A[start]<A[mid]){
                if(target>=A[start]&&target<A[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else if(A[start]>A[mid]){
                if(target>A[mid]&&target<=A[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }else{
                start++;
            }
            
        }   
        return false;
    }
};
