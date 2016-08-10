#include"header.h"
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word2.size()==0)return word1.size();
        if(word1.size()==0)return word2.size();
        vector<int>DP(word2.size()+1,0);
        for(int j=0;j<word2.size()+1;j++){
            DP[j]=j;
        }
        int newDpIj=0;
        for(int i=1;i<word1.size()+1;i++)
        {
            int newDpJminus1=i;//DP[i][j-1]
            for(int j=1;j<word2.size()+1;j++){
                newDpIj=DP[j-1];
                if(word2[j-1]!=word1[i-1]){
                    newDpIj=min(DP[j-1],DP[j]);
                    newDpIj=min(newDpIj,newDpJminus1);
                    newDpIj++;
                }
                DP[j-1]=newDpJminus1;
                newDpJminus1=newDpIj;
            }
            DP[word2.size()]=newDpIj;
        }
        return newDpIj;
    }
};
int main(int argc,char**argv){
    Solution s;
    cout<<s.minDistance("ab","b")<<endl;
}
