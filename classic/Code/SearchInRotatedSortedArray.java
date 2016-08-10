public class Solution {
    int help(int [] A,int target,int start,int end){
        int mid=(start+end)/2;
        if(end-start<1){
            return -1;
        }
        if(end-start==1){
            if(A[start]==target){
                return start;
            }else{
                return -1;
            }
        }
        if(A[mid]==target){
            return mid;
        } 
        if(A[start]==target){
            return start;
        } 
        if(A[end-1]==target){
            return end-1;
        } 
        if (A[mid]>=A[start]){
            if(target>A[mid]){
                return help(A,target,mid+1,end-1);
            }else{
                return help(A,target,start+1,end-1);
            }
        }else {
            if(target<A[mid]){
                return help(A,target,start+1,mid);
            }else{
                return help(A,target,start+1,end-1);
            }
        }
    }
    public int search(int[] A, int target) {
        if(A.length==0){return -1;}
        return help(A,target,0,A.length);
    }
}
