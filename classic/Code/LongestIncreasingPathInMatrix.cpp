class Solution {

public:

    int dfs(int x,int y,int&m, int&n, vector<vector<int> >&matrix,vector<vector<int> >&dis){

        int dx[]={1,-1,0,0};

        int dy[]={0,0,1,-1};

        if(dis[x][y]!=0){

            return dis[x][y];

        }

        for(int i=0;i<4;i++){

            int nx=x+dx[i];

            int ny=y+dy[i];

            if(nx>=0&&ny>=0&&nx<m&&ny<n&&matrix[nx][ny]>matrix[x][y]){

                dis[x][y]=max(dis[x][y],dfs(nx,ny,m,n,matrix,dis));

            }

        }

        dis[x][y]++;

        return dis[x][y]; 

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        if (matrix.size()==0){

            return 0;

        }

        int m=matrix.size();

        int n=matrix[0].size();

        //设dis[i][j]为当前点出发最大上升路径的值。初始设置为0，表示该点未知，需要更新。

        vector<vector<int> >dis(m,vector<int>(n,0));

        int ans=0;

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                ans=max(ans,dfs(i,j,m,n,matrix,dis));

            }

        }

        return ans;

    }

    

};
