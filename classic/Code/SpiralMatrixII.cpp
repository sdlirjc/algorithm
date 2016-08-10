class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int xd[4]={0,1,0,-1};
        int yd[4]={1,0,-1,0};
        int visited=0;
        
        vector<vector<int> >v;
        for(int i=0;i<n;i++){
            vector<int>l(n,0);
            v.push_back(l);
        }
        int i=0;
        int j=0;
        int x=0;
        while(visited<n*n){
            v[i][j]=++visited;
            int nextI=i+xd[x];
            int nextJ=j+yd[x];
            if(nextI>=n||nextI<0||v[nextI][nextJ]!=0||nextJ>=n||nextJ<0){
                x=(x+1)%4;
            }
            i+=xd[x];
            j+=yd[x];
        }
        return v;
    }
};
