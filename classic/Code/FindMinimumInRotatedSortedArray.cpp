#include "header.h"
class Solution {
public:
    int find(vector<int> &num,int start,int end){
        if(end-start==1){return num[start];}
        if(end-start==2){return min(num[start],num[start+1]);}
        if (num[start]<num[end-1]){
            return num[start];
        }else{
            int mid=(start+end)/2;
            if(num[mid]>num[start]){
                return find(num,mid,end);
            }else{
                return find(num,start,mid+1);
            }
        }
    }
    int findMin(vector<int> &num) {
        return find(num,0,num.size());
    }
};
int main(){
    Solution s;
    int input[]={3,1,2};
    vector<int>num;
    for(int i=0;i<sizeof(input)/sizeof(input[0]);i++){
        num.push_back(input[i]);
    }
    cout<<s.findMin(num)<<endl;
}
