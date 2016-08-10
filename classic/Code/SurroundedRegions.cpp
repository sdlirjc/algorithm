class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m=board.size();
        if (m==0) return;
        int n=board[0].size();
        queue<int>q;
        set<int>s;
        for (int i=0;i<m;i++){
            if(board[i][0]=='O'&&s.find(i*n)==s.end()){
                q.push(i*n);
                s.insert(i*n);
            }
            if(board[i][n-1]=='O'&&s.find(i*n+n-1)==s.end()){
                q.push(i*n+n-1);
                s.insert(i*n+n-1);
            }
        }
        for (int i=0;i<n;i++){
            if(board[0][i]=='O'&&s.find(i)==s.end()){
                q.push(i);
                s.insert(i);
            }
            if(board[m-1][i]=='O'&&s.find((m-1)*n+i)==s.end()){
                q.push((m-1)*n+i);
                s.insert((m-1)*n+i);
            }
        }
        while (!q.empty()){
            int i=q.front();
            q.pop();
            int x=i/n;
            int y=i%n;
            board[x][y]='Y';
            if(x>0&&(board[x-1][y]=='O'||board[x-1][y]=='Y')&&s.find((x-1)*n+y)==s.end()) {
                q.push((x-1)*n+y);
                s.insert((x-1)*n+y);
            }
            if(x<m-1&&(board[x+1][y]=='O'||board[x+1][y]=='Y')&&s.find((x+1)*n+y)==s.end()) {
                q.push((x+1)*n+y);
                s.insert((x+1)*n+y);
            }
            if(y>0&&(board[x][y-1]=='O'||board[x][y-1]=='Y')&&s.find(x*n+y-1)==s.end()) {
                q.push(x*n+y-1);
                s.insert(x*n+y-1);
            }
            if(y<n-1&&(board[x][y+1]=='O'||board[x][y+1]=='Y')&&s.find(x*n+y+1)==s.end()) {
                q.push(x*n+y+1);
                s.insert(x*n+y+1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='Y'){
                    board[i][j]='O';
                }
            }
        }
    }
};
