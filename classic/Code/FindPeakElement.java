//For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
public class Solution {
    public int findPeakElement(int[] num) {
        if(num.length==1)return 0;
        if(num[1]<num[0])return 0;
        if(num[num.length-1]>num[num.length-2])return num.length-1;
        for(int i=1;i<num.length-1;i++){
            if(num[i]>num[i-1]&&num[i]>num[i+1]){
                return i;
            }
        }
        return 0;
    }
}
