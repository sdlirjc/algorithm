//http://fmarss.blogspot.com/2014/08/leetcode-solution-maximal-rectangle.html
#include"header.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m=matrix.size();
        if(!m){return 0;}

        int n=matrix[0].size();
        vector<vector<int> >hist(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++) {
            for(int j=n-1;j>=0;j--){
                hist[i][j]=matrix[i][j]=='0'?0:hist[i][j+1]+1;
            }
        }
        int sum=0;
        //http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
        for(int i=0;i<n;i++) {
            stack<int>S;
            for(int j=0;j<m+1;j++){
                if(S.empty()||hist[j][i]>hist[S.top()][i]){
                    S.push(j);
                }else{
                    int tmp=S.top();
                    S.pop();
                    sum=max(sum,hist[tmp][i]*(S.empty()?j:j-S.top()-1));
                    j--;
                }
            }
        }
        return sum;
    }
};

int main(int argc,char**argv){
    Solution s;
    vector<char>v;
    v.push_back('0');
    vector<vector<char> >vv;
    vv.push_back(v);
    s.maximalRectangle(vv);
}
