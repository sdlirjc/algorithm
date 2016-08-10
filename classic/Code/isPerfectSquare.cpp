class Solution {

public:

    bool isPerfectSquare(int num) {

        if (num==0){return true;}

        if (num==1){return true;}

        if (num==2||num==3){return false;}

        long long start = 1 ; 

        long long right = num>>1+1;

        while(start<=right){

            int m = ( start + right ) >>1  ; 

            int mul = m* m ; 

            if(mul==num){

                return true;

            }else if (mul>num){

                right = m -1 ; 

            }else {

                start = m + 1 ; 

            }

        }

        return false;

    }

};
