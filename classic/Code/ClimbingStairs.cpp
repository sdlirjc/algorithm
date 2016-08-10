class Solution {

public:

    int climbStairs(int n) {

        int f1=2,f2=1;

        int f;

        if(n==1)return 1;

        else if(n==2)return 2;

        else {

            for(int i=2;i<n;i++){

                f=f1+f2;

                f2=f1;

                f1=f;

            }

            return f;

        }

    }

};
