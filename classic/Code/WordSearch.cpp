#include "header.h"

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
        bool t=false;
        for(int i=0;i<m;i++) for (int j =0;j<n;j++){
            bool * visited = new bool[m*n];  
            for(int i=0;i<m*n;i++){
                visited[i]=false;
            }
            t=t||existIj(board,word,i,j,visited);
            delete(visited);
        }
        return t; 
    }
    bool existIj(vector<vector<char> > &board, string word, int i , int j , bool * visited){
        
        char w=word[0];
        
        if(board[i][j]==w&&!visited[i*n+j]){
            if(word.size()==1)return true;
            char w1=word[1];
            bool t=false;
            if(i<m-1&&board[i+1][j]==w1&&!visited[(i+1)*n+j]){t=t||existIj(board,word.substr(1),i+1,j,visited);}
            if(i>1&&board[i-1][j]==w1&&!visited[(i-1)*n+j]){t=t||existIj(board,word.substr(1),i-1,j,visited);}
            if(j<n-1&&board[i][j+1]==w1&&!visited[i*n+j+1]){t=t||existIj(board,word.substr(1),i,j+1,visited);}
            if(j>1&&board[i][j-1]==w1&&!visited[i*n+j-1]){t=t||existIj(board,word.substr(1),i,j-1,visited);}
            return t;
        }else{
            return false;
        }
    }
};




int main(int argc,char**argv){
    Solution s ;
    //cout<<s.pow(1.0,-2147483648)<<endl;
    cout<<s.exist()<<endl;
    return 0;
}

