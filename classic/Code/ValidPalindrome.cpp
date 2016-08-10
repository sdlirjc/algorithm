class Solution {
public:
    char an(char a){
        if(a>='A'&&a<='Z'){
            a=a-'A'+'a';
            return a;
        }
        if((a>='a'&&a<='z')||(a>='0'&&a<='9')){
            return a;
        }
        return '+';
    }
    bool isPalindrome(string s) {
        int ind=0;
        for(int i=0;i<s.size();i++){
            char tmp=an(s[i]);
            if(tmp!='+'){
                s[ind]=tmp;
                ind++;
            }
        }
        for(int i=0;i<ind;i++){
            if(s[i]!=s[ind-1-i]){
                return false;
            }
        }
        return true;
    }
};
