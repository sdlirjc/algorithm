#include "header.h"

class Solution {
public:
    string normalize(string str){
        vector<int>a(26,0);
        
        for(int i=0;i<str.size();i++){
            int j=(str[i]-'a')%26;
            a[j]=a[j]+1;
        }
        string r="";
        for(char i=0;i<26;i++){
            if(a[i]>0){
                char c=i+'a';
                r+=c;
                r.append(to_string(a[i]));
            }
        }
        return r;
    }
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string,int>freq;
        unordered_map<string,string>map;
        vector<string>result;
        if(strs.size()==0||strs.size()==1){
            return result;
        }
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            string d=normalize(s);
            cout<<"d: "<<d<<endl;
            if(freq.find(d)!=freq.end()){
                freq[d]++;
            }else{
                freq[d]=1;
            }
            map[s]=d;
        }
        for(int i=0;i<strs.size();i++){
            if(freq[map[strs[i]]]>1){
                cout<<freq[map[strs[i]]]<<endl;
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};
int main(int argc, char**argv){
    Solution s;
    vector<string>input;
    //input.push_back("bat");
    //input.push_back("tab");
    input.push_back("");
    input.push_back("");
    vector<string>output=s.anagrams(input);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
    return 0;
}
