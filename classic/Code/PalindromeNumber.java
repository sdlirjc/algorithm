public class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)return false;
        if(x==0)return true;
        int n=0;
        int tmp=x;
        while(tmp>0){
            tmp/=10;
            n++;
        }
        for(int i=0;i<n;i++){
            int a=(int)(x/Math.pow(10,i))%10;
            int b=(int)(x/Math.pow(10,n-1-i))%10;
            if(a!=b)return false;
        }
        return true;
    }
}
