class Solution {

public:

    bool isValidSudoku(vector<vector<char> > &board) {

        bool r[9][9];

        bool c[9][9];

        bool v[9][9];

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

                if(r[i][a]||c[j][a]||v[(i/3)*3+j/3][a]) return false;

                r[i][a]=true;

                c[j][a]=true;

                v[(i/3)*3+j/3][a]=true;

            }

        }

        return true;

    }

};
