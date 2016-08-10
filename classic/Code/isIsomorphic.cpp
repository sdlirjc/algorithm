/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

*/
class Solution {
public:
    void build(map<char,int> & mapS,vector<char> & vS, map<char,vector<int> > &mvS, int & countS, string & s){
        for(int i=0;i<s.size();i++){
            if(mapS.find(s[i])==mapS.end()){
                mapS.insert(pair<char,int>(s[i],countS));
                vS.push_back(s[i]);
                vector<int>tmp;
                tmp.push_back(i);
                mvS.insert(pair<char,vector<int> >(s[i],tmp));
                countS++;
            }else{
                mvS[s[i]].push_back(i);
            }
        }
    }
    bool isIsomorphic(string s, string t) {
        if(s.size()==0||t.size()==0){return true;}
        if(s.size()!=t.size()){return true;}
        if(s==t){return true;}
        int n = s.size();
        map<char,int> mapS;
        vector<char> vS;
        map<char,vector<int> > mvS;
        map<char,int> mapT;
        vector<char> vT;
        map<char,vector<int> > mvT;
        int countS;
        int countT;
        build(mapS, vS, mvS, countS, s);
        build(mapT, vT, mvT, countT, t);
        for(map<char,vector<int> >::iterator it=mvS.begin();it!=mvS.end();it++){
            vector<int>tmp=mvT[vT[mapS[it->first]]];
            for(int i=0;i<tmp.size();i++){
                if(tmp[i]!=it->second[i]){
                    return false;
                }
            }
        }
        return true; 
    }
};
