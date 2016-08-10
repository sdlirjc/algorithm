class Solution {
public:
    map<char,int>getMap(string s){
        map<char,int>m;
        for(char c:s){
            if(m.count(c)==0){
                m[c]=1;
            }else{
                m[c]=m[c]+1;
            }
        }
        return m;
    }
    bool isAnagram(string s, string t) {
        map<char,int>ms=getMap(s);
        map<char,int>mt=getMap(t);
        for(char c:s){
            if(mt[c]!=ms[c]){
                return false;
            }
        }
        for(char c:t){
            if(mt[c]!=ms[c]){
                return false;
            }
        }
        return true;
    }
};
