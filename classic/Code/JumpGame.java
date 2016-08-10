public class Solution {
    public boolean canJump(int[] A) {
        int start=0;
        int boundary=0;
        while(start<=boundary&&start<A.length){
            boundary=Math.max(boundary,start+A[start]);
            if(boundary>=A.length-1){
                return true;
            }
            start++;
        }
        return false;
    }
}
