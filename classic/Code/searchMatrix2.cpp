class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int n=matrix.size();/*Row*/
        int m=matrix[0].size();/*Col*/
        if (target<matrix[0][0]||target>matrix[n-1][m-1]){
            return false;
        }else{
            bool dirHor = true ; 
            for (int i=0, j=m-1;i<n&&j>=0;){
                if(target==matrix[i][j]){
                    return true;
                }else if(target<matrix[i][j]){
                    j--;
                    continue;
                }else{
                    i++;
                    continue;
                }
            }
            return false;
        }
    }
};
