#include <vector>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.size()==0&&str.size()>0){
            return false;
        }
        map<char,string>pat_str;
        set<string>values;
        int pre=0;
        int counter=0;
        for(int i=0;i<str.size();i++){
            if(str[i]==' '||i==str.size()-1){
                string word="";
                if(str[i]==' '){
                    word=str.substr(pre,i-pre);
                }else{
                    word=str.substr(pre,i-pre+1);
                }
                if(pat_str.count(pattern[counter])){
                    if (pat_str[pattern[counter]]!=word){
                        return false;
                    }
                }else{
                    if(values.count(word)){
                        return false;
                    }else{
                        pat_str[pattern[counter]]=word;
                        values.insert(word);
                    }
                }
                counter++;
                pre=i+1;
            }
        }
        if(counter<pattern.size()){
            return false;
        }else{
            return true; 
        }
    }
};

int main(int argc, char**argv){
    Solution s;
    cout<<s.wordPattern("abba","dog cat cat dog")<<endl;
}
