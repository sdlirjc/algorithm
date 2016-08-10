#include "header.h"

class Solution {

public:

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size()+s2.size()!=s3.size())return false;

        if(s1.size()==0) return s2.compare(s3)==0;

        if(s2.size()==0) return s1.compare(s3)==0;

        if(s1[0]==s3[0]){

            if(s2[0]==s3[0]) return isInterleave(s1.substr(1), s2,  s3.substr(1))||isInterleave(s1, s2.substr(1),  s3.substr(1));

            else return isInterleave(s1.substr(1), s2,  s3.substr(1)); 

        } else{

            if(s2[0]==s3[0]) return isInterleave(s1, s2.substr(1),  s3.substr(1)); 

            else return false;

        }

    }

};


int main(int argc,char**argv){
    Solution s ;
    cout<<s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")<<endl;
    return 0;
}
