/*296. Best Meeting Point  QuestionEditorial Solution  My Submissions
Total Accepted: 6049
Total Submissions: 12525
Difficulty: Hard
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Show Hint 
Show Company Tags
Show Tags
Show Similar Problems
*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int>ii;
        vector<int>jj;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    ii.push_back(i);
                    jj.push_back(j);
                }
            }
        }
        sort(jj.begin(),jj.end());
        int c=ii.size();
        int s=0;
        int io = ii[c/2];
        int jo = jj[c/2];
        for(int i=0;i<ii.size();i++){
            s+=abs(io-ii[i])+abs(jo-jj[i]);
        }
        return s;
    }
};
