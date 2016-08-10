#include<stdio.h>
#include<vector>
#include<math.h>
#include<iostream>
using namespace std;

class Solution {

public:

    vector<int> countBits(int num) {

        vector<int>v;

        v.push_back(0);

        if(num==0){

            return v;

        }

        v.push_back(1);

        if(num==1){

            return v;

        }

        int power=0;

        for (int i=0;i<num;i++){

            if(pow(2,i+1)>num){

                power=i;

                break;

            }

        }
        cout<<power<<endl;
        for(int i=0;i<=power;i++){

            int n=v.size();

            for(int j=0;j<n;j++){

                if(v.size()<=num){

                    v.push_back(v[j]+1);

                }

            }

        }

        return v;

    }

};

int main(){
    Solution s;
    s.countBits(2);
}
