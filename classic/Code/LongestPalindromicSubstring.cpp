class Solution {

public:

    string longestPalindrome(string s) {

        int n = s.size();

        int dp[n][n];

        memset(dp,0,n*n*sizeof(int));

        dp[0][0]=1;

        int maxL=0;

        string maxSubstring="";

        for(int j=0;j<n;j++){

            for(int i=j;i>=0;i--){

                if(i==j){

                    dp[i][j]=1;

                }else{

                    if(j==i+1){

                        dp[i][j]=(s[i]==s[j]);

                    }else{

                        if(i+1<n&&j-1>=0){

                            dp[i][j]=((s[i]==s[j])&&(dp[i+1][j-1]));

                        }

                    }

                }

                if(dp[i][j]){

                    if(j-i+1>maxL){

                        maxL=j-i+1;

                        maxSubstring=s.substr(i,j-i+1);

                    }

                }

            }

        }

        return maxSubstring;

    }

    /* 定义函数

P[i,j] = 字符串区间[i,j]是否为palindrome.



首先找个例子，比如S="abccb",

    S=    a  b  c  c  b

Index = 0  1  2  3  4



P[0,0] =1  //each char is a palindrome

P[0,1] =S[0] == S[1]    , P[1,1] =1

P[0,2] = S[0] == S[2] && P[1,1], P[1,2] = S[1] == S[2] , P[2,2] = 1

P[0,3] = S[0] == S[3] && P[1,2], P[1,3] = S[1] == S[3] && P[2,2] , P[2,3] =S[2] ==S[3],  P[3,3]=1      

......................

由此就可以推导出规律



P[i,j] = 1  if i ==j

        =  S[i] ==S[j]   if j = i+1

        =  S[i] == S[j] && P[i+1][j-1]  if j>i+1

*/

};
