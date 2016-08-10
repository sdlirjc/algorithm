public class Solution {
    public int lengthOfLastWord(String s) {
        int n=s.length();
        if(s.length()==0){
            return 0;
        }
        int counter=0;
        int index=s.length()-1;
        while(index>=0&&s.charAt(index)==' '){
            index--;
        }
        while(index>=0&&s.charAt(index)!=' '){
            counter++;
            index--;
        }
        return counter;
    }
}
