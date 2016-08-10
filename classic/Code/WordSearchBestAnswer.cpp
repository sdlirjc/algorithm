class Solution {
    int m;
    int n;
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size()==0)return false;
        if(word.size()==0)return true;
        char w=word[0];
        m=board.size();
        n=board[0].size();
        if(m*n<word.length())return false;
        bool * visited = new bool[m*n];  
        for(int i=0;i<m*n;i++){
            visited[i]=false;
        }
        for(int i=0;i<m;i++) for (int j =0;j<n;j++){
            if(board[i][j]==w){
                visited[i*n+j]=1;
                if(existIj(board,word,i,j,visited,-1,1)){return true;}
                visited[i*n+j]=0;
            }
        }
        delete(visited);
        return false; 
    }
    bool existIj(vector<vector<char> > &board, string word, int i , int j , bool * visited,int direction,int start){
        if(start==word.size()){
            return true;
        }
        if(i+1<m&&direction!=0){
            if(visited[i*n+n+j]==0&&board[i+1][j]==word[start]){
                visited[i*n+n+j]=1;
                if(existIj(board,word,i+1,j,visited,1,start+1)){
                    return true;
                }
                visited[i*n+n+j]=0;
            }
        }
        if(i-1>=0&&direction!=1){
            if(visited[i*n-n+j]==0&&board[i-1][j]==word[start]){
                visited[i*n-n+j]=1;
                if(existIj(board,word,i-1,j,visited,0,start+1)){
                    return true;
                }
                visited[i*n-n+j]=0;
            }
        }
        if(j+1<n&&direction!=2){
            if(visited[i*n+j+1]==0&&board[i][j+1]==word[start]){
                visited[i*n+j+1]=1;
                if(existIj(board,word,i,j+1,visited,3,start+1)){
                    return true;
                }
                visited[i*n+j+1]=0;
            }
        }
        if(j+1>=0&&direction!=3){
            if(visited[i*n+j-1]==0&&board[i][j-1]==word[start]){
                visited[i*n+j-1]=1;
                if(existIj(board,word,i,j-1,visited,2,start+1)){
                    return true;
                }
                visited[i*n+j-1]=0;
            }
        }
        return false;
    }
};

