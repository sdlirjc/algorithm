#include "header.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int > result;
        int row=matrix.size();
        if(!row)return result;
        int col=matrix[0].size();
        if(!col)return result;
        int x[4]={0,1,0,-1};//row
        int y[4]={1,0,-1,0};//col
        int visitedRows=0;
        int visitedCols=0;
        int direction=0;
        int startX=0;
        int startY=0;
        int candidateNum=0;
        int moveStep=0;
        do{
            candidateNum=y[direction]!=0?col-visitedCols:row-visitedRows;
            if(candidateNum<=0)break;
            result.push_back(matrix[startX][startY]);
            moveStep++;
            if(candidateNum==moveStep){
                visitedRows+=abs(y[direction]);
                visitedCols+=abs(x[direction]);
                direction=(direction+1)%4;
                moveStep=0;
            }
            startX+=x[direction];
            startY+=y[direction];
            cout<<startX<<" "<<startY<<endl;
        }while(candidateNum>0);
        return result;
    }
};
int main(){
    Solution s ;
    vector<int>cell;
    cell.push_back(2);
    cell.push_back(3);
    vector<vector<int> >input;
    input.push_back(cell);
    s.spiralOrder(input);
}
