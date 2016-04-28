class Solution {

public:

    int integerBreak(int n) {

        vector<int>dp(n,0);

        dp[0]=1;

        dp[1]=2;

        dp[2]=3;

        if(n==1){

            return 1;

        }else if (n==2){

            return 1;

        }else if (n==3){

            return 2;

        }

        for (int i=4;i<=n;i++){

            dp[i-1]=max(3*dp[i-4],2*dp[i-3]);

        }

        return dp[n-1];

    }

};
