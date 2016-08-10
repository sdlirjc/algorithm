class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(target<matrix[0][0]||target>matrix[m-1][n-1]) return false;
        int iSave=0;
        for(int i=0;i<m;i++){
            if(target>=matrix[i][0]&&target<=matrix[i][n-1]) {
                iSave=i;
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(target==matrix[iSave][j]) return true;
        }
        return false;
    }
};
