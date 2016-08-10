class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1) return 1;
        if(n==1) return 1;
        int a[m][n];
        for(int i=0;i<m;i++){a[i][0]=1;}
        for(int i=0;i<n;i++){a[0][i]=1;}
        for(int i=1;i<m;i++)for(int j=1;j<n;j++){
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
        return a[m-1][n-1];//uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};
