class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}
        int d=1;
        int tmp=x;
        while (tmp/10){
            tmp=tmp/10;
            d++;
        }
        for(int i=0;i<d/2;i++){
            int right=int(x/pow(10,i))%10;
            int left=int(x/pow(10,d-i-1))%10;
            if(right!=left){return false;}
        }
        return true;
    }
};
