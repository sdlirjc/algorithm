class Solution {
private:
    vector<vector<string> > repo;
    int cnt;
    int N;
public:
    bool isValid(vector<int>state,int row,int col){
        for(int i=0;i<row;i++){
            if(state[i]==col)return false;
            if(abs(i-row)==abs(state[i]-col))return false;
        }
        return true;
    }
    void add(vector<int>state){
        vector<string>v(N);
        for (int i=0;i<N;i++){
            string str(N,'.');
            str[state[i]]='Q';
            v[i]=str;
        }
        repo.push_back(v);
    }
    void check(vector<int>state,int row){
        int n = state.size();
        if(row==n){
            cnt++;
            add(state);
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
    vector<vector<string> > solveNQueens(int n) {
        N=n;
        vector<int> state(n,-1);
        cnt=0;
        check(state,0);
        return repo;
        
    }
};
