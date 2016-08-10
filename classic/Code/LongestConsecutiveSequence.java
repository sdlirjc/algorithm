public class Solution {
    public static int longestConsecutive(int[] num) {
        if(num.length==0){
            return 0;
        }
        Set<Integer>set=new HashSet<Integer>();
        for (int i:num){
            set.add(i);
        }
        int m=0;
        for(int e:num){
            int left=e-1;
            int right=e+1;
            int counter=1;
            while(set.contains(left)){
                counter++;
                set.remove(left);
                left--;
            }
            while(set.contains(right)){
                counter++;
                set.remove(right);
                right++;
            }
            m=Math.max(counter,m);
        }
        return m;
    }
}
