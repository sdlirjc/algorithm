import java.util.*;
import java.io.*;
public class Subsets {
    public List<List<Integer>> subsets(int[] S) {
        List<Integer>list=new ArrayList<Integer>();
        List<List<Integer>>val=new ArrayList<List<Integer>>();
        if(S.length==0){
            val.add(list);
            return val;
        }
        int e=S[0];
        int rest[]=new int[S.length-1];
        int counter=0;
        for(int e1:S){
            if(e1!=e){
                rest[counter]=e1;
                counter++;
            }
        };
        List<List<Integer>>sub=subsets(rest);
        for(int i=0;i<sub.size();i++){
            List<Integer>copy=new ArrayList<Integer>();
            for(int j=0;j<sub.get(i).size();j++){
                copy.add(sub.get(i).get(j));
            }
            copy.add(e);
            Collections.sort(copy);
            val.add(copy);
            val.add(sub.get(i));
        }
        return val;
    }
    public static void main(String[]argv){
        TreeNode root=null;
        Subsets ob = new Subsets();
        int sub[]={1,2,3,4,5,6,7,8,10,0};
        //int sub[]={1,2};
        List<List<Integer>>list=ob.subsets(sub);
        for(List<Integer> a:list){
            for(Integer i:a){
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}
