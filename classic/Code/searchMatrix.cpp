#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        if (target<matrix[0][0]||target>matrix[n-1][m-1]){
            return false;
        }else{
            int i=0;
            int startRow=0;
            for (i=0;i<n;i++){
                if(target<=matrix[i][0]){
                    i++;
                    break;
                }
            }
            startRow=i-1;
            int stopRow=0;
            for (i=0;i<n;i++){
                if(target>=matrix[i][n-1]){
                    i--;
                    break;
                }
            }
            stopRow=i+1;
            cout<<startRow<<endl;
            cout<<stopRow<<endl;
            int startCol=0;
            for (i=0;i<m;i++){
                if(target<=matrix[startRow][i]){
                    i++;
                    break;
                }
            }
            startCol=i-1;
            int stopCol=0;
            for (i=m-1;i>=0;i--){
                if(target>=matrix[stopRow][i]){
                    i--;
                    break;
                }
            }
            stopCol=i+1;
            cout<<startCol<<endl;
            cout<<stopCol<<endl;
            for(i=startRow;i<=stopRow;i++){
                for(int j=startCol;j<=stopCol;j++){
                    if (matrix[i][j]==target){
                        return true;
                    }
                }
            }
            return false;
        }
    }
};

int main1(){
    Solution s;
    vector<int>row;
    row.push_back(-1);
    row.push_back(3);
    vector<vector<int> >matrix;
    matrix.push_back(row);
    cout<<s.searchMatrix(matrix,1)<<endl;
}

int main(){
    Solution s;
    vector<int>row;
    row.push_back(1);
    row.push_back(4);
    vector<vector<int> >matrix;
    matrix.push_back(row);
    row.clear();
    row.push_back(2);
    row.push_back(5);
    cout<<s.searchMatrix(matrix,2)<<endl;
}
