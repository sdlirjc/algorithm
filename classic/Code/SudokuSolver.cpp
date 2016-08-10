class Solution {
private:
    bool r[9][9];
    bool c[9][9];
    bool v[9][9];
public:
    bool solver(vector<vector<char> > &board,int index){
        if(index>80)return true;
        int row=index/9;
        int col=index%9;
        if(board[row][col]!='.'){
            return solver(board,index+1);
        }
        for(int val=0;val<9;val++){
            if(c[col][val]==0&&r[row][val]==0&&v[(row/3)*3+col/3][val]==0){
                board[row][col]=val+'1';
                r[row][val]=true;
                c[col][val]=true;
                v[(row/3)*3+col/3][val]=true;
                if (solver(board,index+1)){return true;}
                r[row][val]=false;
                c[col][val]=false;
                v[(row/3)*3+col/3][val]=false;
            }
        }
        board[row][col]='.';
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        
        for(int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                r[i][j]=false;
                c[i][j]=false;
                v[i][j]=false;
            }
        }
        for(int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int a=board[i][j]-'1';
                if(r[i][a]||c[j][a]||v[(i/3)*3+j/3][a]) return ;//not valid
                r[i][a]=true;
                c[j][a]=true;
                v[(i/3)*3+j/3][a]=true;
            }
        }
        solver(board,0);
    }
};
