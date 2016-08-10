public class Solution {
    public String reverseWords(String s) {
        String [] input = s.split(" ");
        if(input.length==0||s.equals(""))return "";
        System.out.println(input.length);
        int iNew=0;
        for (int i=0;i<input.length;i++){
            System.out.println("input[i]:"+input[i]);
            if (input[i].length()>0){
                input[iNew]=input[i];
                System.out.println("input[iNew]:"+input[iNew]);
                iNew++;
            }
        }
        System.out.println("iNew:"+iNew);
        for (int i=0;i<iNew/2;i++){
            String tmp=input[i];
            input[i]=input[iNew-1-i];
            input[iNew-1-i]=tmp;
        }
        String output="";
        for(int i=0;i<iNew-1;i++){
            output+=input[i]+" ";
        }
        output+=input[iNew-1];
        return output;
    }
    static public void main(String [] argv){
        Solution s = new Solution();
        //System.out.println(s.reverseWords("blue is sky the"));
        //System.out.println(s.reverseWords(" 1")+"|");
        System.out.println(s.reverseWords(" a b ")+"|");
    }
}

