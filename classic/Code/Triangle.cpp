class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size=triangle.size();
        int sum[size][size];
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                sum[i][j]=0;
            }
        }
        for (int i=0;i<size;i++){
            sum[size-1][i]=triangle[size-1][i];
        }
        for(int i=size-2;i>=0;i--){
            for(int j=1;j<=i+1;j++){
                sum[i][j-1]=triangle[i][j-1]+min(sum[i+1][j],sum[i+1][j-1]);
            }
        }
        return sum[0][0];
    }
};