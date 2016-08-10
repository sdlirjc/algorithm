#include"header.h"
class Solution {
public:
    bool isScramble(string s1, string s2) {
        vector<int>A(26,0);
        if(s1.size()!=s2.size()){
            return false;
        }
        if(s1.size()==0){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            A[s1[i]-'a']++;
            A[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            cout<<s1<<" "<<s2<<" "<<char(i+'a')<<" "<<A[i]<<endl;
            if(A[i]!=0)return false;
        }
        if(s1.size()==1&&s2.size()==1){
            return true;
        }
        for(int i=1;i<s1.size();i++){
            bool original=isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i,s1.size()-i),s2.substr(i,s2.size()-i));
            bool scramble=isScramble(s1.substr(0,i),s2.substr(s2.size()-i,i))&&isScramble(s1.substr(i,s1.size()-i),s2.substr(0,s2.size()-i));
            bool result=original||scramble;
            cout<<s1<<" "<<s2<<" "<<original<<" "<<scramble<<" "<<result<<endl;
            if(result){
                return true;
            }
        }   
        return false;
    }
};
int main(int argc,char**argv){
    Solution s;
    cout<<s.isScramble("great","retga")<<endl;
}
