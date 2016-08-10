#include "header.h"

class Solution {

public:

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size()+s2.size()!=s3.size())return false;

        if(s1.size()==0) return s2.compare(s3)==0;

        if(s2.size()==0) return s1.compare(s3)==0;

        /*if(s1[0]==s3[0]){

            if(s2[0]==s3[0]) return isInterleave(s1.substr(1), s2,  s3.substr(1))||isInterleave(s1, s2.substr(1),  s3.substr(1));

            else return isInterleave(s1.substr(1), s2,  s3.substr(1)); 

        } else{

            if(s2[0]==s3[0]) return isInterleave(s1, s2.substr(1),  s3.substr(1)); 

            else return false;

        }*/

        bool yes[s2.size()+1];

        yes[0]=true;

        for(int i=1;i<=s2.size();i++){ yes[i]=s2[i-1]==s3[i-1]; }

        for(int j=1;j<=s1.size();j++){ 

            yes[0]=s1[j-1]==s3[j-1];

            for(int i=1;i<=s2.size();i++){ 

                yes[i]=(yes[i-1]&&s2[i-1]==s3[i+j-1])||(yes[i]&&s1[j-1]==s3[i+j-1]);

            }

        }

        return yes[s2.size()];

    }

};

int main(int argc,char**argv){
    Solution s ;
    //cout<<s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")<<endl;
    cout<<s.isInterleave("ab","bc","bbac")<<endl;
    //cout<<s.isInterleave("ab","bc","abbc")<<endl;
    return 0;
}
