class Solution {
public:
    bool isValid(string s) {
        stack<char>sta;
        for(int i=0;i<s.size();i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='('){
                sta.push(s[i]);
            }else{
                if(sta.empty()){
                    return false;
                }else{
                    char c=sta.top();
                    if(s[i]==']'&&c=='['){
                        sta.pop();
                        continue;
                    } 
                    if(s[i]=='}'&&c=='{'){
                        sta.pop();
                        continue;
                    } 
                    if(s[i]==')'&&c=='(') {
                        sta.pop();
                        continue;
                    }
                }
            }
        }
        if (sta.empty())return true;
        else{return false;}
    }
};
