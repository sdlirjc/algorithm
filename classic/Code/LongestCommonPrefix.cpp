#include <sstream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <string>
#include <vector>
#include <stack>  
#include <string>

using namespace std;

class Solution {

public:

    string longestCommonPrefix(vector<string> &strs) {

        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];

        int m=strs[0].size();

        for (int i=1;i<strs.size();i++){

            int n=strs[i].size();

            m=min(n,m);

        }

        string s;

        for (int i=0;i<m;i++){

            char c=strs[0][i];

            bool b=1;

            for(int j=1;j<strs.size();j++){

                if(strs[j][i]!=c){

                    b=0;

                    break;

                }

            }

            if(b==1){s+=c;}

            else{return s;}

        }

        return s; 

    }

};


int main(int argc , char**argv){
    Solution s;
    vector<string> in;
    s.longestCommonPrefix(in);

}
