public class Solution {
    int search(int[]A,int target,int start,int end){
        int mid=(start+end)/2;
        if(start>=end)return -1;
        if(end-start==1){return A[start]==target?start:-1;}
        if(A[mid]==target){return mid;}
        if(A[start]==target){return start;}
        if(A[end-1]==target){return end-1;}
        if(A[mid]>target){
            return search(A,target,start+1,mid);
        }else{
            return search(A,target,mid+1,end-1);
        }
    }
    public int[] searchRange(int[] A, int target) {
        int val[]={-1,-1};
        int index=search(A,target,0,A.length);
        if(index==-1){
            return val;
        }else{
            int left=index;
            int right=index;
            while((left>=0)&&A[left]==target){
                left--;
            }
            while(right<A.length&&A[right]==target){
                right++;
            }
            val[0]=left+1;
            val[1]=right-1;
        }
        return val;
    }
}
