class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > accumulate=grid;
        int m=accumulate.size();
        int n=accumulate[0].size();
        for(int i=m-2;i>=0;i--){
            accumulate[i][n-1]+=accumulate[i+1][n-1];
        }
        for(int i=n-2;i>=0;i--){
            accumulate[m-1][i]+=accumulate[m-1][i+1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                accumulate[i][j]=min(accumulate[i+1][j],accumulate[i][j+1])+accumulate[i][j];
            }
        }
        return accumulate[0][0];
    }
};
