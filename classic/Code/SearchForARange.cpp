class Solution {
public:
    int search(int A[],int start,int end, int target){
        if(start>end)return -1;
        if(start==end){
            if(target==A[start]){
                return start;
            }else{
                return -1;
            }
        }
        int mid=(start+end)/2;
        if(target>A[end]||target<A[start])return -1;
        if(target>A[mid]){
            if(mid==start){
                return search(A,mid+1,end,target);
            }else{
                return search(A,mid,end,target);
            }
        }else if(target<A[mid]){
            return search(A,start,mid,target);
        }else{
            return mid;
        }
        return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> range;
        int ind=search(A,0,n-1,target);
        if(ind==-1){
            range.push_back(-1);
            range.push_back(-1);
        }else{
            int start=0;
            int end=n-1;
            for (int i=ind;i<n;i++){
                if(A[i]!=target){
                    end=i-1;
                    break;
                }
            }
            for(int i=ind;i>=0;i--){
                if(A[i]!=target){
                    start=i+1;
                    break;
                }
            }
            range.push_back(start);            
            range.push_back(end);            
        }
        return range;
    }
};
