#include "header.h"
class Solution {
public:

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> >ret;
        int n=num.size();
        if(n==0)return ret;
        if(n==1){
            ret.push_back(num);
            return ret;
        }
        perm(num,0,ret);
        return ret;
    }
    void perm(vector<int> num,int step,vector<vector<int> >&ret) {
        int n=num.size();
        if(step==n){
            ret.push_back(num);
            return ;
        }
        for(int i=step;i<n;i++){
            cout<<"step: "<<step<<" i: "<<i<<" ";
            for(int j=0;j<num.size();j++){
                cout<<num[j]<<" ";
            }
            cout<<endl;
            bool swapped=false;
            for(int j=step;j<i;j++){
                if(num[j]==num[i]){
                    swapped=true;
                    break;
                }
            }
            if(!swapped){
                /*int tmp=num[step];
                num[step]=num[i];
                num[i]=tmp;*/
                swap(num[step],num[i]);
                perm(num,step+1,ret);
                /*tmp=num[step];
                num[step]=num[i];
                num[i]=tmp;*/
                swap(num[step],num[i]);
            }
        }
    }
};
int main(){
    Solution s ;
    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    vector<vector<int> >vv=s.permuteUnique(v);
    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++){
            cout<<vv[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


