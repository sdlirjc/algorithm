class Solution {
public:
    int calc(int i, int j, int m, int n, vector<vector<int>>& board){
        int tmp=0;
        if(i>0&&j>0)tmp+=board[i-1][j-1];
        if(i>0)tmp+=board[i-1][j];
        if(i>0&&j<n-1)tmp+=board[i-1][j+1];
        if(j>0)tmp+=board[i][j-1];
        if(j<n-1)tmp+=board[i][j+1];
        if(i<m-1&&j>0)tmp+=board[i+1][j-1];
        if(i<m-1)tmp+=board[i+1][j];
        if(i<m-1&&j<n-1)tmp+=board[i+1][j+1];
        return tmp;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> > newboard = board ; 
        int m=board.size();/*Row*/
        int n=board[0].size();/*Col*/
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int neighbor=calc(i, j, m, n, board);
                if(neighbor==3){
                    newboard[i][j]=1;
                }else if(neighbor>3||neighbor<2){
                    newboard[i][j]=0;
                }else {
                    newboard[i][j]=board[i][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=newboard[i][j];
            }
        }
    }
};
