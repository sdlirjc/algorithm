#include "header.h"
class Solution {
private:
    //vector<vector<int> > repo;
    int cnt; 
public:
    bool isValid(vector<int>state,int row,int col){
        for(int i=0;i<row;i++){
            if(state[i]==col)return false;
            if(abs(i-row)==abs(state[i]-col))return false;
        }
        return true;
    }
    void check(vector<int>state,int row){
        int n = state.size();
        if(row==n){
            cnt++;
        }else{
            for(int i=0;i<n;i++){
                if(isValid(state,row,i)) {
                    state[row]=i;
                    check(state,row+1);
                    state[row]=-1;
                }
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> state(n,-1);
        cnt=0;
        check(state,0);
        return cnt;//repo.size();
    }
};
int main(int argc,char**argv){
    Solution s;
    cout<<s.totalNQueens(8)<<endl;
}
