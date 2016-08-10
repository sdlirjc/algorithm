class Solution {
public:
    int longestValidParentheses(string s) {
        int length=0;
        stack<int>left;
        int lastInd=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')left.push(i);
            else{
                if(left.empty()){
                    lastInd=i;
                }else{
                    left.pop();
                    if(left.empty()){
                        length=max(length,i-lastInd);
                    }else{
                        length=max(length,i-left.top());
                    }
                    
                }
            }
        }
        return length;
        
    }
};
