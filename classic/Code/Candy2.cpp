#include"header.h"
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int>candy(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }
        for(int i=ratings.size()-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                candy[i-1]=candy[i]+1;
            }else if(ratings[i-1]<ratings[i]){
                if(candy[i-1]>candy[i]){
                    if(i==ratings.size()-1){
                        candy[i]=1;
                    }else{
                        candy[i]=candy[i-1]+1;
                    }
                }
            }
        }
        int sum=0;
        for(int i=0;i<ratings.size();i++){
            sum+=candy[i];
            cout<<candy[i]<<" ";
        }
        cout<<endl;
        return sum;
    }
};
int main(){
    Solution s;
    int input[]={4,2,3,4,1};
    vector<int>v;
    for(int i=0;i<sizeof(input)/sizeof(input[0]);i++){
        v.push_back(input[i]);
    }
    s.candy(v);
}
