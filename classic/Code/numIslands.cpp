class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(m==0){
            return 0;
        }
        int n=grid[0].size();
        if(n==0){
            return 0;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!='1'){
                    continue;
                }
                ans++;
                dfs(grid,i,j, m, n);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid,int  i, int  j, int & m, int & n ){
        if(i<0||i>=m||j<0||j>=n){
            return ;
        }
        if(grid[i][j]!='1'){
            return;
        }else{
            grid[i][j]='2';
        }
        dfs(grid,i+1,j, m, n);
        dfs(grid,i-1,j, m, n);
        dfs(grid,i,j+1, m, n);
        dfs(grid,i,j-1, m, n);
    }
};
