#include "header.h"

class Solution {
public:
    vector<vector<int> >  threeSumClosest(vector<int> &num, int target) {
        int n=num.size();
        set<string>container;
        vector<vector<int> >val;
        vector<string>numStr(n);
        if (n==0){
            return val;
        }
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            numStr[i]=to_string(num[i]);
        }
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=num[i]+num[start]+num[end];
                //string s=numStr[i]+":"+numStr[start]+":"+numStr[end];
                //cout<<s<<endl;
                if(sum==target){
                    string s=numStr[i]+":"+numStr[start]+":"+numStr[end];
                    //cout<<s<<endl;
                    if(container.find(s)==container.end())container.insert(s);
                    start++;
                    //val.push_back(candidate);
                    //break;
                }else if(sum>target){
                    end--;
                }else{
                    start++;
                }
            }
        }
        set<string>::iterator it;
        for(it=container.begin();it!=container.end();it++){
            cout<<*it<<endl;
            size_t limit1=(*it).find(':');
            string str1=(*it).substr(0,limit1);
            string str23=(*it).substr(limit1+1);
            size_t limit2=str23.find(':');
            string str2=str23.substr(0,limit2);
            string str3=str23.substr(limit2+1);
            vector<int>candidate(3,0);
            candidate[0]=atoi(str1.c_str());
            candidate[1]=atoi(str2.c_str());
            candidate[2]=atoi(str3.c_str());
            val.push_back(candidate);
        }
        return val;
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        return threeSumClosest(num,0);
    }
};
int main(){
    Solution s ;
    int A[]={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
//{-2,0,1,1,2};
    int N=sizeof(A) / sizeof(A[0]);
    vector<int>num(N,0);
    for(int i=0;i<N;i++){
        num[i]=A[i];
    }
    cout<<s.threeSum(num).size()<<endl;
}
