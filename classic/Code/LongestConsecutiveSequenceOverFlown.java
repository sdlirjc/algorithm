import java.util.*;
public class LongestConsecutiveSequence {
    HashMap<Integer,Integer>index;//num->index
    List<Integer>length;
    int help(int number){
        if(!this.index.containsKey(new Integer(number))){
            return 0;
        }
        Integer ind=new Integer(this.index.get(number));
        if(length.get(ind)>0){
            return length.get(ind);
        }
        length.set(ind,help(number-1)+1);
        return length.get(ind);
    }
    public int longestConsecutive(int[] num) {
        if(num.length==0){
            return 0;
        }
        if(num.length==1){
            //System.out.println("DEBUG1");
            return 1;
        }
        index=new HashMap<Integer,Integer>();
        length=new ArrayList<Integer>();
        for(int i=0;i<num.length;i++){
            this.index.put(num[i],i);
            length.add(0);
        }
        for(int i=0;i<num.length;i++){
            if(length.get(i)>0)continue;
            length.set(i,help(num[i]));
        }
        int m=0;
        for(int i=0;i<length.size();i++){
            m=Math.max(m,length.get(i));
        }
        return m;
    }
    public static void main(String[]argv){
        int input[]=new int[1];
        input[0]=0;
        LongestConsecutiveSequence ob=new LongestConsecutiveSequence();
        System.out.println(ob.longestConsecutive(input));
    }
}
