class Solution {

public:

    bool wordBreak(string s, unordered_set<string> &dict) {

        s='#'+s;

        int sl=s.length();

        bool p[sl];

        p[0]=true;

        for(int i=1;i<sl;i++) p[i]=false;

        for(int i=1;i<sl;i++){

            for(int j=0;j<i;j++){

                p[i]=p[j]&&dict.find(s.substr(j+1,i-j))!=dict.end();

                if(p[i]) break;

            }

        }

        return p[sl-1];

    }

};
